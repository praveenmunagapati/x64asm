/*
Copyright 2103 eric schkufza

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#ifndef X64ASM_SRC_ST_H
#define X64ASM_SRC_ST_H

#include <iostream>

#include "src/operand.h"

namespace x64asm {

/** The ith element from the top of the FPU register stack 
	  (i = 0 through 7). 
*/
class St : public Operand {
	friend class Constants;

	public:
		constexpr bool check() {
			return val_ < 8;
		}

		constexpr bool operator<(const St& rhs) {
			return val_ < rhs.val_;
		}

		constexpr bool operator==(const St& rhs) {
			return val_ == rhs.val_;
		}

		constexpr operator uint64_t() {
			return val_;
		}

		void write_att(std::ostream& os) const;
		void write_intel(std::ostream& os) const;

	protected:
		constexpr St(uint64_t val) 
				: Operand{val} { 
		} 
};

/** The top element of the FPU register stack. */
class St0 : public St {
	friend class Constants;

	public:
		constexpr bool check() {
			return val_ == 0;
		}

	private:
		constexpr St0() 
				: St{0} { 
		}
};

} // namespace x64asm

#endif
