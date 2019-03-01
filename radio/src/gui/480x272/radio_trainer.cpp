/*
 * Copyright (C) OpenTX
 *
 * Based on code named
 *   th9x - http://code.google.com/p/th9x
 *   er9x - http://code.google.com/p/er9x
 *   gruvin9x - http://code.google.com/p/gruvin9x
 *
 * License GPLv2: http://www.gnu.org/licenses/gpl-2.0.html
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include "radio_trainer.h"
#include "opentx.h"
#include "libopenui.h"

#define SET_DIRTY()     storageDirty(EE_GENERAL)

RadioTrainerPage::RadioTrainerPage():
  PageTab(STR_MENUTRAINER, ICON_RADIO_TRAINER)
{
}

void RadioTrainerPage::build(FormWindow * window)
{
#define TRAINER_LABEL_WIDTH  180
  GridLayout grid;
  grid.setLabelWidth(TRAINER_LABEL_WIDTH);
  grid.nextLine();

  for (uint8_t i=0; i<NUM_STICKS; i++) {
    uint8_t chan = channel_order(i+1);
    TrainerMix * td = &g_eeGeneral.trainer.mix[chan-1];

    new StaticText(window, grid.getLabelSlot(), TEXT_AT_INDEX(STR_VSRCRAW, (i + 1)));
    auto mode = new Choice(window, grid.getFieldSlot(3,0), STR_TRNMODE, 0, 2, GET_SET_DEFAULT(td->mode));
    if(i == 0) {
      window->setFirstField(mode);
      mode->setFocus();
    }
    auto perc = new NumberEdit(window, grid.getFieldSlot(3, 1), -125, 125, GET_SET_DEFAULT(td->studWeight));
    perc->setSuffix("%");
    new Choice(window, grid.getFieldSlot(3,2), STR_TRNCHN, 0, 3, GET_SET_DEFAULT(td->srcChn));
    grid.nextLine();
  }
  grid.nextLine();

  // Trainer multiplier
  new StaticText(window, grid.getLabelSlot(), STR_MULTIPLIER);
  auto multiplier = new NumberEdit(window, grid.getFieldSlot(3, 0), -10, 40, GET_SET_DEFAULT(g_eeGeneral.PPM_Multiplier));
  multiplier->setDisplayHandler([](BitmapBuffer * dc, LcdFlags flags, int32_t value) {
    drawNumber(dc, 3, 0, value+10, flags | PREC1, 0);
  });
  grid.nextLine();
  grid.nextLine();

  // Trainer calibration
  new StaticText(window, grid.getLabelSlot(), STR_CAL);
  for (int i=0; i<4; i++) {
    #if defined (PPM_UNIT_PERCENT_PREC1)
    auto calib = new NumberEdit(window, grid.getFieldSlot(4,i), 0 , 0, [=]() {  return (ppmInput[i]-g_eeGeneral.trainer.calib[i])*2; }, nullptr, LEFT|PREC1);
#else
    auto calib = new NumberEdit(window, grid.getFieldSlot(4,i), 0 , 0, [=]() {  return (ppmInput[i]-g_eeGeneral.trainer.calib[i])/5; }, nullptr, LEFT);
#endif
    calib->setWindowFlags(REFRESH_ALWAYS);

    FormField::link(multiplier, window->getFirstField());
  }
}

#if 0
bool menuRadioTrainer(event_t event)
{
  uint8_t y;
  bool slave = SLAVE_MODE();

  MENU(STR_MENUTRAINER, RADIO_ICONS, menuTabGeneral, MENU_RADIO_TRAINER, (slave ? 0 : 6), { NAVIGATION_LINE_BY_LINE|2, NAVIGATION_LINE_BY_LINE|2, NAVIGATION_LINE_BY_LINE|2, NAVIGATION_LINE_BY_LINE|2, 0, 0});

  if (slave) {
    lcdDrawText(LCD_W/2, 5*FH, STR_SLAVE, CENTERED|TEXT_COLOR);
    return true;
  }

  LcdFlags attr;
  LcdFlags blink = ((s_editMode>0) ? BLINK|INVERS : INVERS);

  /* lcdDrawText(TRAINER_COLUMN_1, MENU_HEADER_HEIGHT+1, "Mode", HEADER_COLOR);
  lcdDrawText(TRAINER_COLUMN_2, MENU_HEADER_HEIGHT+1, "Weight", HEADER_COLOR);
  lcdDrawText(TRAINER_COLUMN_3, MENU_HEADER_HEIGHT+1, "Source", HEADER_COLOR);
  */

  y = MENU_CONTENT_TOP + FH;

  for (uint8_t i=0; i<NUM_STICKS; i++) {
    uint8_t chan = channel_order(i+1);
    TrainerMix * td = &g_eeGeneral.trainer.mix[chan-1];

    drawSource(MENUS_MARGIN_LEFT, y, MIXSRC_Rud-1+chan, ((menuVerticalPosition==i && CURSOR_ON_LINE()) ? INVERS : 0));

    for (int j=0; j<3; j++) {

      attr = ((menuVerticalPosition==i && menuHorizontalPosition==j) ? blink : 0);

      switch (j) {
        case 0:
          lcdDrawTextAtIndex(TRAINER_COLUMN_1, y, STR_TRNMODE, td->mode, attr);
          if (attr&BLINK) CHECK_INCDEC_GENVAR(event, td->mode, 0, 2);
          break;

        case 1:
          lcdDrawNumber(TRAINER_COLUMN_2, y, td->studWeight, LEFT|attr, 0, NULL, "%");
          if (attr&BLINK) CHECK_INCDEC_GENVAR(event, td->studWeight, -125, 125);
          break;

        case 2:
          lcdDrawTextAtIndex(TRAINER_COLUMN_3, y, STR_TRNCHN, td->srcChn, attr);
          if (attr&BLINK) CHECK_INCDEC_GENVAR(event, td->srcChn, 0, 3);
          break;
      }
    }
    y += FH;
  }

  attr = (menuVerticalPosition==4) ? blink : 0;
  lcdDrawText(MENUS_MARGIN_LEFT, MENU_CONTENT_TOP + 5*FH, STR_MULTIPLIER);
  lcdDrawNumber(TRAINER_COLUMN_1, MENU_CONTENT_TOP + 5*FH, g_eeGeneral.PPM_Multiplier+10, LEFT|attr|PREC1);
  if (attr) CHECK_INCDEC_GENVAR(event, g_eeGeneral.PPM_Multiplier, -10, 40);

  attr = (menuVerticalPosition==5) ? INVERS : 0;
  if (attr) s_editMode = 0;
  lcdDrawText(MENUS_MARGIN_LEFT, MENU_CONTENT_TOP + 6*FH, STR_CAL, attr);
  for (int i=0; i<4; i++) {
#if defined (PPM_UNIT_PERCENT_PREC1)
    lcdDrawNumber(TRAINER_COLUMN_1+i*TRAINER_COLUMN_WIDTH, MENU_CONTENT_TOP + 6*FH, (ppmInput[i]-g_eeGeneral.trainer.calib[i])*2, LEFT|PREC1);
#else
    lcdDrawNumber(TRAINER_COLUMN_1+i*TRAINER_COLUMN_WIDTH, MENU_CONTENT_TOP + 6*FH, (ppmInput[i]-g_eeGeneral.trainer.calib[i])/5, LEFT);
#endif
  }

  if (attr) {
    if (event==EVT_KEY_LONG(KEY_ENTER)){
      memcpy(g_eeGeneral.trainer.calib, ppmInput, sizeof(g_eeGeneral.trainer.calib));
      storageDirty(EE_GENERAL);
      AUDIO_WARNING1();
    }
  }

  return true;
}
#endif
