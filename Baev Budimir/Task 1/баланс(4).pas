program balance1;
const N=256;
var s:string;
A:array [1..N] of integer;    //� ������ ����� ����������� ������ N ����,N ����� ������� ����� ������ �������,� ������ ���� ������ ����� ������� ������ 256


procedure balch (s:string);
var A:array [0..N] of integer;
i,j:integer;
begin
A[0]:=0;


j:=1;



for i:=1 to length(s) do
begin

if s[i]='('then
begin
A[j]:=A[j-1]+1;
inc(j);
end
else
If s[i]=')'then
begin
A[j]:=A[j-1]-1;
inc(j);
end;

end;
j:=j-1;

if (A[j]<>0) then
begin
write('���-�� ����������� ������ �� ����� ���������� �����������');
Exit;
end;

for i:=0 to j do
if (A[i]<0) then
begin
write('������ ',i,' ������ �� ��������������');
Exit;
end;


write('�� ��������������,��������.');
end;



begin
cls;
s:=')(';

balch(s);
end.