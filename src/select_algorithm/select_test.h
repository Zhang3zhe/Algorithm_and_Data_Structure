/**
 * Copyright (c) 2020-02 https://github.com/Zhang3zhe All rights reserved.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef SELECT_TEST_H_
#define SELECT_TEST_H_
#include<iostream>
#include<vector>
#include"select.h"

class SelectTest {
 public:
	 static void TEST() {
		 std::cout << "----- SelectAlgorithmTest: -----" << std::endl;

		 // 4组std::vector： 增序排列、降序排列、有重复数字、单元素的std::vector
		 std::vector<int> data;

		 data = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		 for (size_t i = 0; i < data.size(); ++i) {
			 auto val = ads::select(data.begin(), data.end(), i);
			 judge(val, data[i]);
		 }
		 std::cout << std::endl;

		 data = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
		 for (size_t i = 0; i < data.size(); ++i) {
			 auto val = ads::select(data.begin(), data.end(), i);
			 judge(val, data[i]);
		 }
		 std::cout << std::endl;

		 data = { 5, 5, 5, 5, 5, 4, 4, 4, 4, 4 };
		 for (size_t i = 0; i < data.size(); ++i) {
			 auto val = ads::select(data.begin(), data.end(), i);
			 judge(val, data[i]);
		 }
		 std::cout << std::endl;

		 data = { 5 };
		 for (size_t i = 0; i < data.size(); ++i) {
			 auto val = ads::select(data.begin(), data.end(), i);
			 judge(val, data[i]);
		 }
		 std::cout << std::endl;

		 std::cout << "-----SelectAlgorithmTest over, access rate is " << 100.0 * access_no / case_no << "%. -----" << std::endl;
	 }
 
 private:
	 static int case_no;
	 static int access_no;

	 static void judge(const int lhs, const int rhs) {
		 ++ case_no;
		 if (lhs == rhs) {
			 ++ access_no;
			 std::cout << lhs << "  ";
		 } else {
			 std::cout << lhs << "[X]  ";
		 }
	 }
};

int SelectTest::case_no = 0;
int SelectTest::access_no = 0;

#endif // SELECT_TEST_H_
