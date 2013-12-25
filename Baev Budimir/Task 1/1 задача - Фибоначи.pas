program fibonachyi1;
const N=100000;

function fibon1 (i:integer) : integer;
begin
if i<0 then
write('ошибка1');
if (i=1) or (i=0) then
begin
result:=1;
Exit;
end;

if i>1 then
result:=fibon1(i-1)+fibon1(i-2);

end;



function fibon2  (i:integer) :integer;
var A:array [0..N]of integer;
j:integer;
begin

A[0]:=1;
A[1]:=1;

for j:= 2 to i do
A[j]:=A[j-1]+A[j-2];

if i<0 then
begin
write('ошибка1');
Exit;
end;


result:=A[i];
end;



begin
cls;
write(fibon1(30));
writeln;
write(fibon2(30));
end.