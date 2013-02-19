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

#ifndef X64ASM_SRC_XMM_H
#define X64ASM_SRC_XMM_H

#include <iostream>

#include "src/operand.h"
#include "src/ymm.h"

namespace x64asm {

/** An XMM register. The 128-bit XMM registers are: XMM0 through XMM7; XMM8 
	  through XMM15 are available using REX.R in 64-bit mode.
*/
class Xmm : public Operand {
	friend class Constants;

	public:
		constexpr Ymm parent() { 
			return Ymm{val_}; 
		}

		constexpr bool check() {
			return val_ < 16;
		}

		constexpr bool operator<(const Xmm& rhs) {
			return val_ < rhs.val_;
		}

		constexpr bool operator==(const Xmm& rhs) {
			return val_ == rhs.val_;
		}

		constexpr operator uint64_t() {
			return val_;
		}

		void write_att(std::ostream& os) const;
		void write_intel(std::ostream& os) const;

	protected:
		constexpr Xmm(uint64_t val) 
				: Operand{val} { 
		} 
};

/** The XMM register XMM0. */
class Xmm0 : public Xmm {
	friend class Constants;

	public:
		constexpr bool check() {
			return val_ == 0;
		}

	private:
		constexpr Xmm0() 
				: Xmm{0} { 
		}
};

} // namespace x64asm

#endif
