program include;
var s,s1:string;

function incl(s1,s:string) : integer;
var i,j,t:integer;
begin
result:=0;
if length(s1)>length(s) then result:=0;

for i:=1 to length(s)-length(s1)+1 do
begin
t:=1;
for j:=0 to length(s1)-1 do
if s[i+j] <> s1[j+1] then
begin
t:=0;
Break;
end;

result:=result+t;
end;



end;



begin
cls;
s:=')(()(';
s1:=')(';
write(incl(s1,s));
end.