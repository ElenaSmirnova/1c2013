program bla;
const
N=10;
var A:array [1..N] of integer;
gurb,i,j:integer;

procedure blah(var A:array [1..N] of integer);
var s,k,chl:integer;            //chl - chisel less than A[1] (loooool)
begin
s:=2;
chl:=0;
k:=1;
while (s<N+1) do
begin
if A[k]<=A[s] then inc(s)
else
begin
if s=k+1 then
begin
gurb:=A[k];
A[k]:=A[s];
A[s]:=gurb;
k:=s;
inc(s);
end
else
begin
gurb:=A[k+1];
A[k+1]:=A[k];
A[k]:=A[s];
A[s]:=gurb;
k:=k+1;
inc(s);
end;


end;

end;

end;


begin
cls;
for i:=1 to N do
begin
A[i]:=random(1000);
write(A[i],'; ')
end;

blah(A);

writeln;

for i:=1 to N do
begin
write(A[i],'; ')
end;

end.