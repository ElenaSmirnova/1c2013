program pal;
var s:string;
procedure palindrom (s:string) ;
var i,e:integer;
begin
e:=1;
for i:=1 to round((length(s)+1)/2) do
if s[i]<>s[length(s)-i+1] then
begin
write('��,�� ���������.������� � ��������� ',i,' � ',length(s)-i+1,' �� ���������');
e:=0;
Exit;
end;

if e=1 then
write('� ��-���� ���������');

end;

begin
cls;
s:='23';
palindrom(s);
end.