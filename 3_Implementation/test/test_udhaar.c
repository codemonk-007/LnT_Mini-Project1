#include "unity.h"
#include "udhaar.h"
#define PROJECT_NAME  "UDHAAR"

/* Prototypes for all the test functions */
void test_read_file(void);
void test_write_file(void);
void test_search_contact(void);
void test_update_time_stamp(void);
void test_new_transaction(void);
void test_update_record(void);
void test_display(void);
void test_settle(void);
void test_exit_program(void);
/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}

/* Start of the application test */
int main()
{
/* Initiate the Unity Test Framework */
  UNITY_BEGIN();

/* Run Test functions */
  RUN_TEST(test_read_file);
  RUN_TEST(test_write_file);
  RUN_TEST(test_search_contact);
  RUN_TEST(test_update_time_stamp);
  //RUN_TEST(test_new_transaction);
  //RUN_TEST(test_update_record);
  RUN_TEST(test_display);
  //RUN_TEST(test_settle);
  RUN_TEST(test_exit_program);

  /* Close the Unity Test Framework */
  return UNITY_END();
}

/* Write all the test functions */ 
void test_read_file(void){
    TEST_ASSERT_EQUAL(read_file(),1);
}
void test_write_file(void){
  TEST_ASSERT_EQUAL(write_file(),1);
}
void test_search_contact(void){
    ll contact = 0;
    TEST_ASSERT_EQUAL(search_contact(contact),-1);
    contact = 9871997207;
    TEST_ASSERT_EQUAL(search_contact(contact),0);
}
void test_update_time_stamp(void){

    int pos = -1;
  TEST_ASSERT_EQUAL(update_time_stamp(pos),0);
  pos = 2;
  TEST_ASSERT_EQUAL(update_time_stamp(pos),1);

}

void test_new_transaction(void){

    ll contact = 0; bool from_update = false;
    TEST_ASSERT_EQUAL(new_transaction(contact,from_update),1);
    contact = 9871997207;from_update = true;
    TEST_ASSERT_EQUAL(new_transaction(contact,from_update),2);
}

void test_update_record(void){
  ll contact = 0;
  TEST_ASSERT_EQUAL(update_record(contact),2);
  contact = 9871997207;
  TEST_ASSERT_EQUAL(update_record(contact),1);
}

void test_display(void){
  TEST_ASSERT_EQUAL(display(),1);
}
void test_settle(void){
  TEST_ASSERT_EQUAL(settle(),2);
  TEST_ASSERT_EQUAL(settle(),1);
}
void test_exit_program(void){
  TEST_ASSERT_EQUAL(exit_program(),1);
}

