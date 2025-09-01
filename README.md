# begincendator
Converts curly brackets of c source into numered begins and ends and back.

The valid begvns and ends can have letters in lower and upper case. Begin can have short form "beg". For example begin can be like: "begin0", "Begin0", "BEGIN0", "bEGin0", "Beg0", "beg0", "bEg0".

The numbers of opening and closing brackets are from 0 in strict order. Before and after begin or and must be carriage return character or space character. For example:

int foo(int a) begin0

for(int i = 0; i < 10; ++i) begin1

++a;

end1

return a;

end0
