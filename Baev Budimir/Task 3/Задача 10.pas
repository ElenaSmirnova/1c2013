program hsgdhsdghdfgh;
Type Uk=^W;
W=RECORD;
Inf:integer;
Next:Uk;
end;
var S:string;
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
function che(s:string):integer ;
var Ki,Li:Uk;
i:integer;
begin
Li:=nil;
for i:=1 to length(s) do
begin


If s[i]='(' then
begin
New(Ki);
Ki^.Inf:=i;
Ki^.Next:=Li;
Li:=Ki;
end;

If s[i]=')'then
begin
If Li=nil then
begin
result:=i;
Exit;
end
else
begin
Li:=Li^.Next;
end;
end;


If (s[i]<>'(') and (s[i]<>')') then
begin
write('This string is not a bracket sequence');
result:=-3;
Exit;
end;

end;

If Li=nil then
result:=-1             //(rus)eta skobochanya posledovatelnost pravilnyaya;
else result:=-2;       //(rus)ne yavlayetsya pravilnoi,ibo mnogo otcrivaushich skobok;





end;
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
begin
cls;
S:='((((())))()';
write(che(S));


end.