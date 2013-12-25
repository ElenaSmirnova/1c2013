program qethtwrjhwgebndfghfg;
const N=100000;
Type uk1=^R;
uk2=^S;
R=record;
Inf:integer;
Fo:uk1;
Ba:uk1;
end;
S=record;
Inf:integer;
Uka:uk2;
end;
var w1,w2,w3,w4,w5,u7:uk1;
u1,u2,u3,u4,u5,u6,w7:uk2;
t1,t2,t3,t4:uk2;
i:integer;
A:array
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
function mo(var Hi:uk1):uk1;
var Ri,Ti,Ki:uk1;
begin

If Hi=nil then
begin
result:=nil;
Exit;
end;


If  Hi^.Fo=nil then
begin
result:=Hi;
Exit;
end;

Ki:=Hi;

If Ki^.Inf <= Ki^.Fo^.Inf then
begin
result:=Hi;
Exit;
end
else
begin

Ti:=Ki^.Fo;
Ri:=Ki;
If Ti^.Fo<>nil then
Ti^.Fo^.Ba:=Ri;

If Ri^.Ba<>nil then
Ri^.Ba^.Fo:=Ti;

Ri^.Fo:=Ti^.Fo;
Ti^.Fo:=Ri;
Ti^.Ba:=Ri^.Ba;
Ri^.Ba:=Ti;

Ti^.Fo:=mo(Ri);

result:=Ti;

end;

end;
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
function sort(var Hi:uk1):uk1;                            //задание 7//подразумевается,что список не зацикливается.Списку сопоставляется левый/первый элемент отсортированного.Можно просто удалять старый,но подобное можно написать и в программе.
var Ti,Ki,Li:uk1;
begin
If Hi=nil then
begin
result:=nil;
Exit;
end;


Ki:=Hi;
Ti:=Ki^.Fo;
Li:=sort(Ti);
Ki^.Fo:=Li;
If Li<>nil then
Li^.Ba:=Ki;
result:=mo(Ki);

end;
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
function obb (Hi1,Hi2:uk2):uk2;   //задача 8         //считается заранее,что списки отсортированы;списки,естественно,односвязны.
var Ti:uk2;
begin
New(Ti);
If Hi1=nil then
begin
result:=Hi2;
Exit;
end;

If Hi2=nil then
begin
result:=Hi1;
Exit;
end;


If Hi1^.Inf< Hi2^.Inf then
begin
Ti^.Inf:=Hi1^.Inf;
Ti^.Uka:=obb(Hi1^.Uka,Hi2);
end
else
begin
Ti^.Inf:=Hi2^.Inf;
Ti^.Uka:=obb(Hi1,Hi2^.Uka);
end;


result:=Ti;
end;
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
function dep(Hi:uk1):uk1;                 //задание 9
var Ki,Li:uk1;
begin
New(Li);
New(Ki);
If Hi=nil then
begin
result:=nil;
Exit;
end;

if Hi^.Inf>0 then
begin
result:=dep(Hi^.Fo);
Exit;
end
else begin
Ki:=dep(Hi^.Fo);
Li^.Fo:=Ki;
Li^.Inf:=Hi^.Inf;
If Ki<>nil then
Ki^.Ba:=Li;

result:=Li;
end;

end;
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
function ad(Hi:uk2;e,f:integer):uk2;                  //задание 10
var Ti,Ki,Li:uk2;
begin
New(Ti);
New(Li);
If Hi=nil then begin
result:=nil;
Exit;
end;

Ki:=ad(Hi^.Uka,e,f);
Li^.Uka:=Ki;
Li^.Inf:=Hi^.Inf;

If Hi^.Inf=e then
begin
Ti^.Inf:=f;
Ti^.Uka:=Ki;
Li^.Uka:=Ti;

end;
result:=Li;
end;
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

begin
cls;
New(w1);
New(w2);
New(w3);
New(w4);
New(w5);
New(u1);
New(u2);
New(u3);
New(u4);
New(u5);
New(u6);
New(t1);
New(t2);
New(t3);
New(t4);
New(u7);
New(w7);
{w1^.Ba:=nil;
w1^.Fo:=w2;
w2^.Ba:=w1;
w2^.Fo:=w3;
w3^.Ba:=w2;
w3^.Fo:=w4;
w4^.Ba:=w3;
w4^.Fo:=nil;
Readln(w1^.Inf);
Readln(w2^.Inf);
Readln(w3^.Inf);
Readln(w4^.Inf);  }
u1^.Uka:=u2;
u2^.Uka:=u3;
u3^.Uka:=u4;
u4^.Uka:=u5;
u5^.Uka:=nil;


{t1^.Uka:=t2;
t2^.Uka:=t3;
t3^.Uka:=t4;
t4^.Uka:=nil;}
u1^.Inf:=-6;
u2^.Inf:=-6;
u3^.Inf:=-2;
u4^.Inf:=1;
u5^.Inf:=2;
{t1^.Inf:=1;
t2^.Inf:=2;
t3^.Inf:=3;
t4^.Inf:=4;}

{u6:=obb(u1,t1);   }
{u7:=dep(w1);}
w7:=ad(u1,-6,0);
{while u7<>nil do
begin
writeln(u7^.Inf);
u7:=u7^.Fo;
end;}
while w7<>nil do
begin
writeln(w7^.Inf);
w7:=w7^.Uka;
end;
{w5:=sort(w1)};
writeln;
{writeln(w5^.Inf);
writeln(w5^.Fo^.Inf);
writeln(w5^.Fo^.Fo^.Inf);
writeln(w5^.Fo^.Fo^.Fo^.Inf);}
{while u6<>nil do
begin
writeln(u6^.Inf);
u6:=u6^.Uka;
end;      }
Dispose(w1);
Dispose(w2);
Dispose(w3);
Dispose(w4);
Dispose(u1);
Dispose(u2);
Dispose(u3);
Dispose(u4);
Dispose(u5);
Dispose(t1);
Dispose(t2);
Dispose(t3);
Dispose(t4);
{Dispose(w5);    }

end.