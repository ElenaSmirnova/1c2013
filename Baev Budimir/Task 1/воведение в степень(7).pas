program p;

function powder(a:real; n:integer) :real;
begin

if a=0 then
begin write('�� ���� � ���� ���� �� �� ��� ���������')
end;

if n=0 then result:=1;
If n>0 then result:=a*powder(a,n-1);
If n<0 then result:=a*powder(a,n+1);

end;

begin
cls;
write(powder(2.5,4)) ;

end.