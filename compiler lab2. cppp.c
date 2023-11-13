import re

def is_valid_variable_name(variable_name):
    # Define the regular expression for a valid C++ identifier
    identifier_pattern = re.compile(r'^[a-zA-Z_]\w*$')

    # Check if the variable_name matches the pattern
    return bool(identifier_pattern.match(variable_name))

def check_variable_names(source_code):
    # Split the source code into lines
    lines = source_code.split('\n')

    # Regular expression to find variable declarations
    variable_declaration_pattern = re.compile(r'\b(?:int|float|double|char|bool)\s+([a-zA-Z_]\w*)\s*;')

    invalid_variable_names = []

    for line in lines:
        # Check for variable declarations in the line
        match = variable_declaration_pattern.search(line)
        if match:
            variable_name = match.group(1)
            if not is_valid_variable_name(variable_name):
                invalid_variable_names.append(variable_name)

    return invalid_variable_names

# Example usage
cpp_source_code = """
int validVariable;
double invalid-variable;
float anotherValidVariable;
char _valid_variable;
"""

invalid_variables = check_variable_names(cpp_source_code)

if invalid_variables:
    print("Invalid variable names found:")
    for invalid_variable in invalid_variables:
        print(invalid_variable)
else:
    print("No invalid variable names found.")
