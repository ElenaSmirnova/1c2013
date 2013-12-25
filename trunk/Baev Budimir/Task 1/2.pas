program sort;
const
N=10;
Maxu=100;
var
A,B:array [1..N]  of integer;
gurb,i,j:integer;


procedure bubble (var A:array [1..N] of integer);
begin
for j:=1 to N-1 do
for i:=1 to N-1 do
begin
if A[i]>A[i+1] then
begin
gurb:=A[i];
A[i]:=A[i+1];
A[i+1]:=gurb;
end;
end;
end;


procedure count (var B:array [1..N] of integer);
var C:array [1..Maxu] of integer;
begin
for i:=1 to maxu do
C[i]:=0;

for i:=1 to N do
inc(C[B[i]]);

j:=1;

for i:=1 to Maxu do
begin
if C[i]>0 then
for gurb:=1 to C[i] do
begin
B[j]:=i;
inc(j);

end;


end;

end;



begin
cls;
For  gurb:=1 to N do
begin
A[gurb]:= N+1-gurb;
B[gurb]:=N+1-gurb;
end;

bubble(A);
count(B);

For  gurb:=1 to N do
write(A[gurb],'; ');
writeln;

For  gurb:=1 to N do
write(B[gurb],'; ');

end.