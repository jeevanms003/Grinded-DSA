import os
import glob
import re

def parse_cpp_signature(content):
    # Find the function signature inside class Solution
    match = re.search(r'class Solution\s*\{\s*public:\s*([a-zA-Z_<>\s]+)\s+([a-zA-Z_]+)\s*\((.*?)\)', content, re.DOTALL)
    if not match:
        # Check global functions
        match = re.search(r'([a-zA-Z_<>\s]+)\s+([a-zA-Z_]+)\s*\((.*?)\)\s*\{', content)
        if not match:
            return None, None, None
            
    ret_type, func_name, args_str = match.groups()
    args_str = args_str.strip()
    if not args_str:
        args = []
    else:
        args = [arg.strip() for arg in args_str.split(',')]
    return ret_type.strip(), func_name.strip(), args

def generate_cpp_main(ret_type, func_name, args):
    main_code = "\n#include <iostream>\nusing namespace std;\n\nint main() {\n"
    call_args = []
    
    # Check if Solution class exists
    main_code += "    Solution sol;\n"
    caller = "sol."
    
    for arg in args:
        if 'vector<int>' in arg:
            var_name = arg.split('&')[-1].strip()
            if ' ' in var_name: var_name = var_name.split(' ')[-1]
            main_code += f"    int n_{var_name};\n"
            main_code += f"    cin >> n_{var_name};\n"
            main_code += f"    vector<int> {var_name}(n_{var_name});\n"
            main_code += f"    for(int i=0; i<n_{var_name}; i++) cin >> {var_name}[i];\n"
            call_args.append(var_name)
        elif 'int' in arg:
            var_name = arg.split(' ')[-1].strip()
            main_code += f"    int {var_name};\n"
            main_code += f"    cin >> {var_name};\n"
            call_args.append(var_name)
            
    call_str = f"{caller}{func_name}({', '.join(call_args)})"
    if ret_type == 'void':
        main_code += f"    {call_str};\n"
        if len(call_args) > 0 and 'vector<int>' in args[0]: # assume modifying first array
            var_name = call_args[0]
            main_code += f"    for(int x : {var_name}) cout << x << ' ';\n    cout << endl;\n"
    elif ret_type == 'vector<int>':
        main_code += f"    vector<int> res = {call_str};\n"
        main_code += f"    for(int x : res) cout << x << ' ';\n    cout << endl;\n"
    elif ret_type == 'vector<vector<int>>':
        main_code += f"    vector<vector<int>> res = {call_str};\n"
        main_code += f"    for(auto vec : res) {{\n        for(int x : vec) cout << x << ' ';\n        cout << endl;\n    }}\n"
    else:
        main_code += f"    cout << {call_str} << endl;\n"
        
    main_code += "    return 0;\n}\n"
    return main_code

def process_cpp():
    for filepath in glob.glob("cpp/*.cpp"):
        with open(filepath, "r") as f:
            content = f.read()
            
        # Remove old boilerplate if exists
        content = re.sub(r'int main\(\)\s*\{\s*return 0;\s*\}\s*', '', content)
        
        ret_type, func_name, args = parse_cpp_signature(content)
        if ret_type:
            main_code = generate_cpp_main(ret_type, func_name, args)
            
            # Ensure <iostream> is included
            if '#include <iostream>' not in content:
                content = "#include <iostream>\n" + content
            if 'using namespace std;' not in content:
                content = content.replace('#include <iostream>', '#include <iostream>\nusing namespace std;')
                
            with open(filepath, "w") as f:
                f.write(content.strip() + "\n" + main_code)

def parse_py_signature(content):
    match = re.search(r'class Solution:\s*def\s+([a-zA-Z_]+)\(self,\s*(.*?)\)\s*->\s*(.*?):', content, re.DOTALL)
    if not match:
        match = re.search(r'def\s+([a-zA-Z_]+)\((.*?)\)\s*->\s*(.*?):', content)
        if not match: return None, None, None, False
        func_name, args_str, ret_type = match.groups()
        is_class = False
    else:
        func_name, args_str, ret_type = match.groups()
        is_class = True
        
    args_str = args_str.strip()
    if not args_str: args = []
    else: args = [arg.strip() for arg in args_str.split(',')]
    return ret_type.strip(), func_name.strip(), args, is_class

def generate_py_main(ret_type, func_name, args, is_class):
    main_code = "\nif __name__ == '__main__':\n"
    call_args = []
    
    for arg in args:
        if 'list[int]' in arg:
            var_name = arg.split(':')[0].strip()
            main_code += f"    {var_name} = list(map(int, input().split()))\n"
            call_args.append(var_name)
        elif 'int' in arg:
            var_name = arg.split(':')[0].strip()
            main_code += f"    {var_name} = int(input())\n"
            call_args.append(var_name)
            
    caller = "Solution()." if is_class else ""
    call_str = f"{caller}{func_name}({', '.join(call_args)})"
    
    if ret_type == 'None':
        main_code += f"    {call_str}\n"
        if call_args: main_code += f"    print(' '.join(map(str, {call_args[0]})))\n"
    elif ret_type == 'list[int]':
        main_code += f"    res = {call_str}\n"
        main_code += f"    print(' '.join(map(str, res)))\n"
    elif ret_type == 'list[list[int]]':
        main_code += f"    res = {call_str}\n"
        main_code += f"    for r in res:\n        print(' '.join(map(str, r)))\n"
    else:
        main_code += f"    print({call_str})\n"
        
    return main_code

def process_py():
    for filepath in glob.glob("python/*.py"):
        with open(filepath, "r") as f:
            content = f.read()
            
        content = re.sub(r"if __name__ == '__main__':\s*pass\s*", '', content)
        content = re.sub(r'if __name__ == "__main__":\s*pass\s*', '', content)
        
        ret_type, func_name, args, is_class = parse_py_signature(content)
        if ret_type:
            main_code = generate_py_main(ret_type, func_name, args, is_class)
            with open(filepath, "w") as f:
                f.write(content.strip() + "\n" + main_code)

process_cpp()
process_py()
print("Complex boilerplate generation complete.")
