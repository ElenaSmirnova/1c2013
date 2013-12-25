program bla;
const
N=10;
var A:array [1..N] of integer;
gurb,i,j,middle:integer;

procedure blah(var A:array [1..N] of integer;c,d:integer);
var s,k:integer;
begin
if (c>=d) then
begin
Exit;
end;


s:=c+1;
k:=c;
while (s<d+1) do
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
middle:=k;
end;



procedure sort (var A:array [1..N] of integer;c,d:integer);
var mid1:integer;
i,j:integer;
begin
if (c>=d) then
begin;
Exit;
end;
blah(A,c,d);
mid1:=middle;
sort(A,c,mid1-1);
sort(A,mid1+1,d)

end;


begin
cls;
for i:=1 to N do
begin
A[i]:=random(1000);
write(A[i],'; ')
end;

sort(A,1,N);

writeln;

for i:=1 to N do
begin
write(A[i],'; ')
end;

end.