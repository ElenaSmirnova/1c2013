program pr;
const
M=500;

procedure prime (n:integer);
var A:array [1..M] of integer;
i,j,k,godnota:integer;
begin
if n < 2 then
begin
write('Число должно быть больше единицы');
Exit;
end;

j:=1;
A[1]:=2;
write('2; ');
for i:=2 to n do
begin
godnota:=1;
for k:=1 to j do
begin
if ((i mod A[k])=0)then
begin
godnota:=0;
Break;
end;
end;

If godnota=1 then
begin
A[j+1]:=i;
inc(j);
write(A[j],'; ')
end;

end;



end;




begin
cls;
prime(100);
end.