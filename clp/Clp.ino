// ============================================================ 
//                                                              
// Example: LCDML_104_change_value                         
//                                                            
// ============================================================ 
// This example shows different methods to change values
// For menu element "Set Datetime" thanks to skorpi08 @ arduino forum
// Other methods to change value coming soon
// ============================================================ 

  // include libs
  #include <LiquidCrystal.h>
  #include <LCDMenuLib.h>
  
  // lib config
  #define _LCDML_DISP_cfg_button_press_time          200    // button press time in ms
  #define _LCDML_DISP_cfg_scrollbar                  1      // enable a scrollbar
  #define _LCDML_DISP_cfg_cursor                     0x7E   // cursor Symbol 

// ********************************************************************* 
// LCDML TYPE SELECT
// *********************************************************************
  // settings for lcd 
  #define _LCDML_DISP_cols            16
  #define _LCDML_DISP_rows             2  

  // lcd object
  // liquid crystal needs (rs, e, dat4, dat5, dat6, dat7)
  LiquidCrystal lcd(3, 4, 5, 6, 7, 8);
  
  const uint8_t scroll_bar[5][8] = {
    {B10001, B10001, B10001, B10001, B10001, B10001, B10001, B10001}, // scrollbar top
    {B11111, B11111, B10001, B10001, B10001, B10001, B10001, B10001}, // scroll state 1 
    {B10001, B10001, B11111, B11111, B10001, B10001, B10001, B10001}, // scroll state 2
    {B10001, B10001, B10001, B10001, B11111, B11111, B10001, B10001}, // scroll state 3
    {B10001, B10001, B10001, B10001, B10001, B10001, B11111, B11111}  // scrollbar bottom
  }; 

// *********************************************************************
// LCDML MENU/DISP
// *********************************************************************
  // create menu
  // menu element count - last element id
  // this value must be the same as the last menu element
  #define _LCDML_DISP_cnt   46
  
  // LCDML_root        => layer 0 
  // LCDML_root_X      => layer 1 
  // LCDML_root_X_X    => layer 2 
  // LCDML_root_X_X_X  => layer 3 
  // LCDML_root_... 	 => layer ... 

  
  // LCDMenuLib_add(id, group, prev_layer_element, new_element_num, lang_char_array, callback_function)
  LCDML_DISP_initParam(_LCDML_DISP_cnt);
  // *********************** Menu Principal ******************************
 
  LCDML_DISP_addParam      (0  , _LCDML_G1  , LCDML_root        , 1  , "Inciar operacao"  , Entrada,1);
  LCDML_DISP_addParam      (46  , _LCDML_G1  , LCDML_root_1      , 1  , "Parar operacao?"  , Entrada,2);

  LCDML_DISP_add      (1  , _LCDML_G1  , LCDML_root        , 2  , "Programar"      , LCDML_FUNC);
  LCDML_DISP_add      (2  , _LCDML_G1  , LCDML_root        , 3  , "Relogio"        , LCDML_FUNC_change_datetime);
  LCDML_DISP_add      (3  , _LCDML_G1  , LCDML_root        , 4  , "Prog. prontos"  , LCDML_FUNC);
  LCDML_DISP_add      (45 , _LCDML_G1  , LCDML_root        , 5  , "Testar saidas"  , LCDML_FUNC);
 

      // ************************ Menu Programar ******************************* 
      LCDML_DISP_add      (4  , _LCDML_G1  , LCDML_root_2      , 1  , "Saida 01"      , LCDML_FUNC);
      LCDML_DISP_add      (5  , _LCDML_G1  , LCDML_root_2      , 2  , "Saida 02"      , LCDML_FUNC);
      LCDML_DISP_add      (6  , _LCDML_G1  , LCDML_root_2      , 3  , "Saida 03"      , LCDML_FUNC);
      LCDML_DISP_add      (7  , _LCDML_G1  , LCDML_root_2      , 4  , "Saida 04"      , LCDML_FUNC);

          // ************************ saida01 ******************************* 
          LCDML_DISP_add      (8  , _LCDML_G1  , LCDML_root_2_1      , 1  , "Por Timer"      , LCDML_FUNC);
          LCDML_DISP_add      (9  , _LCDML_G1  , LCDML_root_2_1      , 2  , "Por Entrada"      , LCDML_FUNC);

              LCDML_DISP_addParam      (10  , _LCDML_G1  , LCDML_root_2_1_1      , 1  , "Timer 01"      , Timer,0101);
              LCDML_DISP_addParam      (11  , _LCDML_G1  , LCDML_root_2_1_1      , 2  , "Timer 02"      , Timer,0102);

              LCDML_DISP_addParam      (12  , _LCDML_G1  , LCDML_root_2_1_2      , 1  , "Entrada 01"      , Entrada,0101);
              LCDML_DISP_addParam      (13  , _LCDML_G1  , LCDML_root_2_1_2      , 2  , "Entrada 02"      , Entrada,0102);
              LCDML_DISP_addParam      (14  , _LCDML_G1  , LCDML_root_2_1_2      , 3  , "Entrada 03"      , Entrada,0103);



          // ************************ saida02 ******************************* 
          LCDML_DISP_add      (15  , _LCDML_G1  , LCDML_root_2_2      , 1  , "Por Timer"      , LCDML_FUNC);
          LCDML_DISP_add      (16  , _LCDML_G1  , LCDML_root_2_2      , 2  , "Por Entrada"      , LCDML_FUNC);
              LCDML_DISP_addParam      (17  , _LCDML_G1  , LCDML_root_2_2_1      , 1  , "Timer 01"      , Timer,0201);
              LCDML_DISP_addParam      (18  , _LCDML_G1  , LCDML_root_2_2_1      , 2  , "Timer 02"      , Timer,0202);

              LCDML_DISP_addParam      (19  , _LCDML_G1  , LCDML_root_2_2_2      , 1  , "Entrada 01"      , Entrada,0201);
              LCDML_DISP_addParam      (20  , _LCDML_G1  , LCDML_root_2_2_2      , 2  , "Entrada 02"      , Entrada,0202);
              LCDML_DISP_addParam      (21  , _LCDML_G1  , LCDML_root_2_2_2      , 3  , "Entrada 03"      , Entrada,0203);

          // ************************ saida03 ******************************* 
          LCDML_DISP_add      (22  , _LCDML_G1  , LCDML_root_2_3      , 1  , "Por Timer"      , LCDML_FUNC);
          LCDML_DISP_add      (23  , _LCDML_G1  , LCDML_root_2_3      , 2  , "Por Entrada"      , LCDML_FUNC);
              LCDML_DISP_addParam      (24  , _LCDML_G1  , LCDML_root_2_3_1      , 1  , "Timer 01"      , Timer,0301);
              LCDML_DISP_addParam      (25  , _LCDML_G1  , LCDML_root_2_3_1      , 2  , "Timer 02"      , Timer,0302);

              LCDML_DISP_addParam      (26  , _LCDML_G1  , LCDML_root_2_3_2      , 1  , "Entrada 01"      , Entrada,0301);
              LCDML_DISP_addParam      (27  , _LCDML_G1  , LCDML_root_2_3_2      , 2  , "Entrada 02"      , Entrada,0302);
              LCDML_DISP_addParam      (28  , _LCDML_G1  , LCDML_root_2_3_2      , 3  , "Entrada 03"      , Entrada,0303);

         // ************************ saida04 ******************************* 
          LCDML_DISP_add      (29  , _LCDML_G1  , LCDML_root_2_4      , 1  , "Por Timer"      , LCDML_FUNC);
          LCDML_DISP_add      (30  , _LCDML_G1  , LCDML_root_2_4      , 2  , "Por Entrada"      , LCDML_FUNC);
              LCDML_DISP_addParam      (31  , _LCDML_G1  , LCDML_root_2_4_1      , 1  , "Timer 01"      , Timer,0401);
              LCDML_DISP_addParam      (32  , _LCDML_G1  , LCDML_root_2_4_1      , 2  , "Timer 02"      , Timer,0401);
              
              LCDML_DISP_addParam      (33  , _LCDML_G1  , LCDML_root_2_4_2      , 1  , "Entrada 01"      , Entrada,0401);
              LCDML_DISP_addParam      (34  , _LCDML_G1  , LCDML_root_2_4_2      , 2  , "Entrada 02"      , Entrada,0402);
              LCDML_DISP_addParam      (35  , _LCDML_G1  , LCDML_root_2_4_2      , 3  , "Entrada 03"      , Entrada,0403);
              LCDML_DISP_addParam      (36  , _LCDML_G1  , LCDML_root_2_4_2      , 4  , "Entrada 04"      , Entrada,0404);


      // ************************ Testar Saidas ******************************* 
      LCDML_DISP_add      (37 , _LCDML_G1  , LCDML_root_5     , 1  , "Saida 01"      , LCDML_FUNC);
      LCDML_DISP_add      (38 , _LCDML_G1  , LCDML_root_5     , 2  , "Saida 02"      , LCDML_FUNC);
      LCDML_DISP_add      (39 , _LCDML_G1  , LCDML_root_5     , 3  , "Saida 03"      , LCDML_FUNC);
      LCDML_DISP_add      (40 , _LCDML_G1  , LCDML_root_5     , 4  , "Saida 04"      , LCDML_FUNC);

// ************************ Menu Programas prontos ******************************* 
      LCDML_DISP_add      (41  , _LCDML_G1  , LCDML_root_4      , 1  , "Irrigacao"          , LCDML_FUNC);
      LCDML_DISP_add      (42  , _LCDML_G1  , LCDML_root_4      , 2  , "Contro. Nivel"      , LCDML_FUNC);
      LCDML_DISP_add      (43  , _LCDML_G1  , LCDML_root_4      , 3  , "Contr. Pressao"     , LCDML_FUNC);
      LCDML_DISP_add      (44  , _LCDML_G1  , LCDML_root_4      , 4  , "Contro. Temp."      , LCDML_FUNC);

  LCDML_DISP_createMenu(_LCDML_DISP_cnt);



// ********************************************************************* 
// LCDML BACKEND (core of the menu, do not change here anything yet)
// ********************************************************************* 
  // define backend function  
  #define _LCDML_BACK_cnt    2  // last backend function id
  
  LCDML_BACK_init(_LCDML_BACK_cnt);
  LCDML_BACK_new_timebased_dynamic (0  , ( 20UL )         , _LCDML_start  , LCDML_BACKEND_control);
  LCDML_BACK_new_timebased_dynamic (1  , ( 100000000UL )  , _LCDML_stop   , LCDML_BACKEND_menu);
 LCDML_BACK_new_timebased_static  (2  , ( 500UL )        , _LCDML_stop   , LCDML_BACKEND_static);

  LCDML_BACK_create();


// *********************************************************************
// SETUP
// *********************************************************************
  void setup()
  {  
    
    lcd.begin(_LCDML_DISP_cols,_LCDML_DISP_rows);  
    // set special chars for scrollbar
    lcd.createChar(0, (uint8_t*)scroll_bar[0]);
    lcd.createChar(1, (uint8_t*)scroll_bar[1]);
    lcd.createChar(2, (uint8_t*)scroll_bar[2]);
    lcd.createChar(3, (uint8_t*)scroll_bar[3]);
    lcd.createChar(4, (uint8_t*)scroll_bar[4]);
  
    // Enable all items with _LCDML_G1
    LCDML_DISP_groupEnable(_LCDML_G1); // enable group 1
  
    // LCDMenu Setup
    LCDML_setup(_LCDML_BACK_cnt);  
  }

// *********************************************************************
// LOOP
// *********************************************************************
  void loop()
  { 

    // this function must called here, do not delete it
    LCDML_run(_LCDML_priority); 
    tempo();

}




// *********************************************************************
// check some errors - do not change here anything
// *********************************************************************
# if(_LCDML_DISP_rows > _LCDML_DISP_cfg_max_rows)
# error change value of _LCDML_DISP_cfg_max_rows in LCDMenuLib.h
# endif
# if(_LCDML_DISP_cols > _LCDML_DISP_cfg_max_string_length)
# error change value of _LCDML_DISP_cfg_max_string_length in LCDMenuLib.h
# endif
