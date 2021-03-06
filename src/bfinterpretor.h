#ifndef BF_INTERPRETOR_H
#define BF_INTERPRETOR_H "moo"

#include <string>
#include <map>
#include <vector>
#include <iostream>

typedef uint8_t cellc;

class BFInterpretor {
	public:
		BFInterpretor();
		~BFInterpretor();
		void process(std::string);
		void add_function();

		void _check_dead_syntax(std::string&);
		void _find_function_definitions(std::string&);
		void _check_function_calls(std::string&);
		void interpret(std::string&);
		uint8_t getval();
		void setval(uint8_t);
		void _update_registers();

	private:
		std::map<std::string, std::string> function_register;
		std::map<size_t, uint8_t> memory;
		std::map<size_t, uint64_t> ioregs;
		std::vector<std::string::iterator> loop_register;
		bool pointer_type = false;
		size_t memory_pointer = 0;
		size_t register_pointer = 0;
};

#endif
