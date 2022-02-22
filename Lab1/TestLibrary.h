//
// Created by Toby Dragon on 9/4/18.
//

#ifndef LAB1SOLN_TESTLIBRARY_H
#define LAB1SOLN_TESTLIBRARY_H

/**
 * reports whether ints are equal or not
 * @param expected - the value you expect the actual value to be
 * @param actual - the actual value to test
 * @post prints only "pass" if the values are equal,
 *      Else it prints "FAIL" and their respective values
 */
void printAssertEquals(int expected, int actual);

/**
 * reports whether booleans are equal or not
 * @param expected - the value you expect the actual value to be
 * @param actual - the actual value to test
 * @post prints only "pass" if the values are equal,
 *      Else it prints "FAIL" and their respective values
 */
void printAssertEquals(bool expected, bool actual);

#endif //LAB1SOLN_TESTLIBRARY_H
