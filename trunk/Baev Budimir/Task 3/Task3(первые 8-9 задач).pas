program erhehgfbfdbfgbn;
const N=100000;
Type    Uk=^W;
W=record;
Inf:integer;
Left:Uk;
Right:Uk;
Ba:Uk;
end;
var T:Uk;
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
procedure goi (Hi:Uk);                //������� 1
begin
If Hi=nil then
Exit;

write(' ',Hi^.Inf,' ;');
goi(Hi^.Left);
write(' ',Hi^.Inf,' ;');
goi(Hi^.Right);
write(' ',Hi^.Inf,' ;');

end;
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
procedure adn (var Hi:Uk;const i,pos:integer);                 //������� 2
var Ki:Uk;
begin
if pos<0 then
begin
write('���������� ������ �������');
Exit;
end;
New(Ki);
Ki^.Inf:=i;
if Hi=nil then
begin
write('�������� ������ �����.������!');
Exit;
end;

If pos= 2 then
begin
Ki^.Left:=nil;
Ki^.Right:=Hi^.Right;
Hi^.Right:=Ki;
Ki^.Ba:=Hi;
Exit;
end;

If pos= 1 then
begin
Ki^.Left:=nil;
Ki^.Right:=Hi^.Right;
Hi^.Right:=Ki;
Ki^.Ba:=Hi;
Exit;
end;

if pos mod 3=0 then
begin
write('����������� �������� �������');
Exit;
end;

if pos mod 3 =1 then
begin
adn(Hi^.Right,i,round(pos/2));
end
else  adn(Hi^.Left,i,round(pos/2));


end;
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
procedure ad(var Hi:Uk;const U:Uk;pos:integer);                 //������� 3//���������������,��� ������ ������� �����,� �� �������� ������ ������(�.�. �� ��� ������ ������ Hi �� U).����� ��,��� ���� �� � �����,���������.
begin
if pos<0 then
begin
write('������������ ������ �������.�� ��������.');
Exit;
end;


if Hi=nil then
begin
if pos<>0 then
begin
write(' ���������� ��������� �� ������ �������');
Exit;
end
else
begin Hi:=U;
Exit;
end;
end;


if pos=0 then
begin
write('������ � �������� �������*');
Exit;
end;

if pos=1 then
begin
if Hi^.Left<>nil then write('��� ���-�� ����...�� �� ���...����');
Hi^.Left:=U;
U^.Ba:=Hi;
end;

if pos=2 then
begin
if Hi^.Right<>nil then write('��� ���-�� ����...�� �� ���...����');
Hi^.Right:=U;
U^.Ba:=Hi;
end;


if pos mod 3=1 then
ad(Hi^.Left,U,round((pos-1)/3));

if pos mod 3=2 then
ad(Hi^.Right,U,round((pos-2)/3));

end;
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
function mammie(Ui:Uk):Uk;      //������� 4//
begin
If Ui=nil then
begin
write(' � ������� ������ ��� ����� ');
Exit;
end;

If Ui^.Ba=nil then
begin
result:=Ui;
Exit;
end;

result:=mammie(Ui^.Ba);

end;
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
function minpar(Hi,Ui:Uk):Uk ;               //�������5//
var Ki,Li:Uk;
begin

If (Hi^.Ba=nil) or (Ui^.Ba=nil) then
begin
Ki:=mammie(Ui);
Li:=mammie(Hi);
If Ki=Li then
begin
result:=Ki;
Exit;
end;
end;

If Ui=Hi then
begin
result:=Ui;
Exit;
end;

Ki:=minpar(Hi^.Ba,Ui);
Li:=minpar(Hi,Ui^.Ba);

If  Ki=Li then
begin
result:=Ki;
Exit;
end;

If Ki^.Ba=Li then
result:=Ki;

If Li^.Ba=Ki then
result:=Li;

end;
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
function fiw(Hi,Ui:Uk):integer;      // ������������ "����" �� ����� � ������ �������(1-�c�� ������,2 - ���� �������,0-���� ��� ���������,� ��� � �������� �������),��� -1,���� ������ �������� ���.
var ki,li:integer;
begin
If Hi=nil then
begin
result:=-1;
Exit;
end;

ki:=fiw(Hi^.Left,Ui);
li:=fiw(Hi^.Right,Ui);

if ki=li then
begin
write('������ � ��� �����-��...�� ������.��� � ������� ���� ��� ������');
Exit;
end;

If ki>-1 then
begin
result:=3*ki+1;
Exit;
end;

if li>-1 then
begin
result:=3*li+2;
Exit;
end;

result:=-1;

end;
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
procedure delwo (var Hi:Uk;const Ui:Uk);   //�������7//�� ������ �� ���������
begin
If Hi=nil then
begin
Exit;
end;

If Hi=Ui then
begin
Hi:=nil;
Exit;
end;

delwo(Hi^.Right,Ui);
Delwo(Hi^.Left,Ui);


end;
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
procedure delel(var Hi:Uk;const Ui:Uk);       //������� 8//�������� ��������,���� �� ����(������������ ��������,��� �� ���� �� ����� ���� ����� �Ĩ�)
begin
if Hi=nil then
begin
Exit;
end;

If (Ui^.Left<>nil)  and (Hi^.Right<>nil) then
begin
write('������� � ����� �������.�� ��������');
Exit;
end;

If Ui^.Left=nil then
begin
If Hi=Ui then
begin
Hi:=Ui^.Right;
Exit;
end;

If Hi^.Left=Ui then
begin
Hi^.Left:=Ui^.Right;

if Ui^.Right<>nil then
Ui^.Right^.Ba:=Hi;
Exit;
end;


If Hi^.Right=Ui then
begin
Hi^.Right:=Ui^.Right;

if Ui^.Right<>nil then
Ui^.Right^.Ba:=Hi;
Exit;
end;

delel(Hi^.Left,Ui);
delel(Hi^.Right,Ui);

Exit;
end
else
begin


{}


If Hi=Ui then
begin
Hi:=Ui^.Left;
Exit;
end;

If Hi^.Left=Ui then
begin
Hi^.Left:=Ui^.Left;

if Ui^.Left<>nil then
Ui^.Left^.Ba:=Hi;
Exit;
end;


If Hi^.Right=Ui then
begin
Hi^.Right:=Ui^.Left;

if Ui^.Left<>nil then
Ui^.Left^.Ba:=Hi;
Exit;
end;

delel(Hi^.Left,Ui);
delel(Hi^.Right,Ui);


Exit;
end;

end;
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
function wai (Hi:Uk;i:integer):array [1..N] of integer;            //����� ��� ������ �������� �������(������������������ �� 1 � 2,���������� � 3-�����),��� ����� ������ �� i ������,��� �������.
var Ai,Bi,Ci :array [1..N] of integer;
ji,si:integer;
begin
si:=0;
for ji:=1 to N do
Ai[ji]:=-1;

If Hi=nil then
begin
if i=0 then
Ai[1]:=0;
result:=Ai;
Exit;
end;

If (i=1) and (Hi^.Left=nil) and (Hi^.Right=nil)then
begin
Ai[1]:=1;
end;

Bi:=wai(Hi^.Left,i-1);
Ci:=wai(Hi^.Right,i+1);
si:=1;
While Bi[si]<>-1 do
begin
Ai[si]:=3*Bi[si]+1;
inc(si);
end;

ji:=1;
While Ci[ji]<>-1 do
begin
Ai[si+ji]:=3*Ci[ji]+2;
inc(ji);
end;



result:=Ai;

end;
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
procedure settree(var T);
begin
T:=nil;

write('�����');


end;
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
begin
cls;
New(T);
settree(T);

If T<>nil then
Dispose(T);
end.