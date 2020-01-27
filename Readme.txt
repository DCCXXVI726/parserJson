Instruction
1. start with parse_json("file_name"), it will return start object's node.
2. check return statement, if it is 0. you have wrong json file (or i has a problem)
3. use 1 of get functions get_"searching_type"(node, name, container),
container has the type "searching_type".
4. check returb statement, if it is 0. use print_error (function is not ready)
5. free with ft_return (start node) or move to 3 point
"searching_type"
	a. int
	b. double
	c. String (Remark: in container put copy of String, you should free it by himself)
	d. Object
	e. Array
