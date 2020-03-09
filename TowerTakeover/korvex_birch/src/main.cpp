#include "main.h"
#include "korvexlib.h"
#include "okapi/api.hpp"
using namespace okapi;

// chassis

// base global defenitions
int autonSelection = 42; // hitchhikers anyone?

// create a button descriptor string array
static const char *btnmMap[] = {"Left", "Right", "Rick", ""};

static lv_res_t autonBtnmAction(lv_obj_t *btnm, const char *txt)
{
	if (lv_obj_get_free_num(btnm) == 100) {
		if (txt == "Unprotec") autonSelection = -1;
		else if (txt == "Protec") autonSelection = -2;
		else if (txt == "Rick") autonSelection = -3;
	}
	else if (lv_obj_get_free_num(btnm) == 101) {
		if (txt == "Unprotec") autonSelection = 1;
		else if (txt == "Protec") autonSelection = 2;
		else if (txt == "Rick") autonSelection = 3;
	}

	return LV_RES_OK; // return OK because the button matrix is not deleted
}

static lv_res_t skillsBtnAction(lv_obj_t *btn)
{
	autonSelection = 0;
	return LV_RES_OK;
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */

void initialize()
{

	// lvgl theme

	lv_theme_t *th = lv_theme_alien_init(360, NULL); //Set a HUE value and keep font default RED
	lv_theme_set_current(th);

	// create a tab view object
	lv_obj_t *tabview = lv_tabview_create(lv_scr_act(), NULL);

	// add 4 tabs (the tabs are page (lv_page) and can be scrolled
	lv_obj_t *redTab = lv_tabview_add_tab(tabview, "Red");
	lv_obj_t *blueTab = lv_tabview_add_tab(tabview, "Blue");
	lv_obj_t *skillsTab = lv_tabview_add_tab(tabview, "Skills");

	// red tab
	lv_obj_t *redBtnm = lv_btnm_create(redTab, NULL);
	lv_btnm_set_map(redBtnm, btnmMap);
	lv_btnm_set_action(redBtnm, autonBtnmAction);
	lv_obj_set_size(redBtnm, 450, 50);
	lv_btnm_set_toggle(redBtnm, true, 3);
	lv_obj_set_pos(redBtnm, 0, 100);
	lv_obj_align(redBtnm, NULL, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_free_num(redBtnm, 100);

	// blue tab
	lv_obj_t *blueBtnm = lv_btnm_create(blueTab, NULL);
	lv_btnm_set_map(blueBtnm, btnmMap);
	lv_btnm_set_action(blueBtnm, autonBtnmAction);
	lv_obj_set_size(blueBtnm, 450, 50);
	lv_btnm_set_toggle(blueBtnm, true, 3);
	lv_obj_set_pos(blueBtnm, 0, 100);
	lv_obj_align(blueBtnm, NULL, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_free_num(blueBtnm, 101);

	// skills tab
	lv_obj_t *skillsBtn = lv_btn_create(skillsTab, NULL);
	lv_obj_t *label = lv_label_create(skillsBtn, NULL);
	lv_label_set_text(label, "Skills");
	lv_btn_set_action(skillsBtn, LV_BTN_ACTION_CLICK, skillsBtnAction);
	lv_obj_set_size(skillsBtn, 450, 50);
	lv_btnm_set_toggle(skillsBtn, true, 3);
	lv_obj_set_pos(skillsBtn, 0, 100);
	lv_obj_align(skillsBtn, NULL, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_free_num(skillsBtn, 102);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {
	
}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default pchassiosisioriority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */


void autonomous() {
	leftMotor.move_velocity(200);
	rightMotor.move_velocity(200);

	
	pros::delay(1000);
	leftMotor.move_velocity(0);
	rightMotor.move_velocity(0);
	
	

	// chassis->getModel()->turn(45);
	pros::delay(100);
	

	clawMotor.move_absolute(400, 200);
	pros::delay(500);
	clawMotor.move_absolute(0, 200);
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Compeftition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */

void opcontrol() {
	

	// main loop
	while (true) {
		// the tank control
	
		rightMotor.move(masterController.getAnalog(ControllerAnalog::rightY));
		leftMotor.move(masterController.getAnalog(ControllerAnalog::leftY));
//If the arm button is pressed then the arm will move upwards 
	if(armUp.isPressed()){
		liftMotor.move_velocity(200);
	}
//Other Arm button moves the arm downwards
	else if(armDown.isPressed()){
		liftMotor.move_velocity(-200);
	}
//
	else{liftMotor.move_velocity(0);}

	if(clawOpen.isPressed()){
		clawMotor.move_velocity(200);
	}
	else if(clawClose.isPressed()){
		clawMotor.move_velocity(-200);
	}
	else{clawMotor.move_velocity(0);}





		// debug
		std::cout << pros::millis() << ": lift " << liftMotor.get_efficiency() << std::endl;
		pros::delay(20);
	}
}
