Практическое занятие № 5: «Распараллеливание алгоритмов» (для группы ВМ-22м)

1\.Распараллеливание ациклических алгоритмов.



![](Aspose.Words.3aca4f28-6aa9-4b21-9879-37efd7f29867.001.png)


Для каждого блока заданы входные и выходные переменные (см. Таблицу 1).

Таблица 1 – Варианты заданий

<table><tr><th colspan="1" rowspan="2" valign="top"><p>№№ </p><p>блоков</p></th><th colspan="21" valign="top">№ варианта</th></tr>
<tr><td colspan="1" valign="top">1</td><td colspan="1" valign="top">2</td><td colspan="1" valign="top">3</td><td colspan="1" valign="top">4</td><td colspan="1" valign="top">5</td><td colspan="1" valign="top">6</td><td colspan="1" valign="top">7</td><td colspan="1" valign="top">8</td><td colspan="1" valign="top">9</td><td colspan="1" valign="top">10</td><td colspan="1" valign="top">11</td><td colspan="1" valign="top">12</td><td colspan="1" valign="top">13</td><td colspan="1" valign="top">14</td><td colspan="1" valign="top">15</td><td colspan="1" valign="top">16</td><td colspan="1" valign="top">17</td><td colspan="1" valign="top">18</td><td colspan="1" valign="top">19</td><td colspan="1" valign="top">20</td><td colspan="1" valign="top">21</td></tr>
<tr><td colspan="1" valign="top">1</td><td colspan="1" valign="top">cad</td><td colspan="1" valign="top">eac</td><td colspan="1" valign="top">ddg</td><td colspan="1" valign="top">aae</td><td colspan="1" valign="top">bcf</td><td colspan="1" valign="top">cdc</td><td colspan="1" valign="top">bed</td><td colspan="1" valign="top">fdb</td><td colspan="1" valign="top">dcb</td><td colspan="1" valign="top">fef</td><td colspan="1" valign="top">bdb</td><td colspan="1" valign="top">gge</td><td colspan="1" valign="top">bfd</td><td colspan="1" valign="top">fcd</td><td colspan="1" valign="top">fff</td><td colspan="1" valign="top">fcf</td><td colspan="1" valign="top">gcf</td><td colspan="1" valign="top">ffg</td><td colspan="1" valign="top">abe</td><td colspan="1" valign="top">gec</td><td colspan="1" valign="top">cac</td></tr>
<tr><td colspan="1" valign="top">2</td><td colspan="1" valign="top">cbe</td><td colspan="1" valign="top">eae</td><td colspan="1" valign="top">efc</td><td colspan="1" valign="top">fdf</td><td colspan="1" valign="top">bfc</td><td colspan="1" valign="top">efe</td><td colspan="1" valign="top">aea</td><td colspan="1" valign="top">fbc</td><td colspan="1" valign="top">edd</td><td colspan="1" valign="top">ccf</td><td colspan="1" valign="top">bde</td><td colspan="1" valign="top">edg</td><td colspan="1" valign="top">fba</td><td colspan="1" valign="top">ceg</td><td colspan="1" valign="top">ega</td><td colspan="1" valign="top">feg</td><td colspan="1" valign="top">fca</td><td colspan="1" valign="top">add</td><td colspan="1" valign="top">fef</td><td colspan="1" valign="top">ced</td><td colspan="1" valign="top">eae</td></tr>
<tr><td colspan="1" valign="top">3</td><td colspan="1" valign="top">ecb</td><td colspan="1" valign="top">ecg</td><td colspan="1" valign="top">bbe</td><td colspan="1" valign="top">deg</td><td colspan="1" valign="top">adb</td><td colspan="1" valign="top">bff</td><td colspan="1" valign="top">dfb</td><td colspan="1" valign="top">cac</td><td colspan="1" valign="top">ddc</td><td colspan="1" valign="top">ede</td><td colspan="1" valign="top">cea</td><td colspan="1" valign="top">egc</td><td colspan="1" valign="top">dee</td><td colspan="1" valign="top">eed</td><td colspan="1" valign="top">adg</td><td colspan="1" valign="top">cfd</td><td colspan="1" valign="top">bcf</td><td colspan="1" valign="top">fgc</td><td colspan="1" valign="top">bff</td><td colspan="1" valign="top">abg</td><td colspan="1" valign="top">bff</td></tr>
<tr><td colspan="1" valign="top">4</td><td colspan="1" valign="top">ba</td><td colspan="1" valign="top">cf</td><td colspan="1" valign="top">gc</td><td colspan="1" valign="top">db</td><td colspan="1" valign="top">ea</td><td colspan="1" valign="top">ce</td><td colspan="1" valign="top">fd</td><td colspan="1" valign="top">df</td><td colspan="1" valign="top">cf</td><td colspan="1" valign="top">fd</td><td colspan="1" valign="top">cb</td><td colspan="1" valign="top">gd</td><td colspan="1" valign="top">fe</td><td colspan="1" valign="top">bg</td><td colspan="1" valign="top">fd</td><td colspan="1" valign="top">fe</td><td colspan="1" valign="top">ef</td><td colspan="1" valign="top">ab</td><td colspan="1" valign="top">gf</td><td colspan="1" valign="top">gb</td><td colspan="1" valign="top">ce</td></tr>
<tr><td colspan="1" valign="top">5</td><td colspan="1" valign="top">ccd</td><td colspan="1" valign="top">aec</td><td colspan="1" valign="top">bed</td><td colspan="1" valign="top">eda</td><td colspan="1" valign="top">eea</td><td colspan="1" valign="top">cgb</td><td colspan="1" valign="top">bdc</td><td colspan="1" valign="top">af f</td><td colspan="1" valign="top">ffb</td><td colspan="1" valign="top">dde</td><td colspan="1" valign="top">ddf</td><td colspan="1" valign="top">fcc</td><td colspan="1" valign="top">efd</td><td colspan="1" valign="top">dfc</td><td colspan="1" valign="top">bae</td><td colspan="1" valign="top">edb</td><td colspan="1" valign="top">dbb</td><td colspan="1" valign="top">dbb</td><td colspan="1" valign="top">bbe</td><td colspan="1" valign="top">dfe</td><td colspan="1" valign="top">cab</td></tr>
<tr><td colspan="1" valign="top">6</td><td colspan="1" valign="top">efe</td><td colspan="1" valign="top">ecb</td><td colspan="1" valign="top">bge</td><td colspan="1" valign="top">eab</td><td colspan="1" valign="top">ffc</td><td colspan="1" valign="top">eaf</td><td colspan="1" valign="top">bff</td><td colspan="1" valign="top">abb</td><td colspan="1" valign="top">beg</td><td colspan="1" valign="top">bfg</td><td colspan="1" valign="top">fec</td><td colspan="1" valign="top">cga</td><td colspan="1" valign="top">cdg</td><td colspan="1" valign="top">dgf</td><td colspan="1" valign="top">ffg</td><td colspan="1" valign="top">bcf</td><td colspan="1" valign="top">eag</td><td colspan="1" valign="top">dbe</td><td colspan="1" valign="top">dea</td><td colspan="1" valign="top">fbe</td><td colspan="1" valign="top">eaf</td></tr>
<tr><td colspan="1" valign="top">7</td><td colspan="1" valign="top">dde</td><td colspan="1" valign="top">ecd</td><td colspan="1" valign="top">fba</td><td colspan="1" valign="top">dfe</td><td colspan="1" valign="top">cce</td><td colspan="1" valign="top">egc</td><td colspan="1" valign="top">abe</td><td colspan="1" valign="top">dce</td><td colspan="1" valign="top">dae</td><td colspan="1" valign="top">bfe</td><td colspan="1" valign="top">fef</td><td colspan="1" valign="top">bbc</td><td colspan="1" valign="top">gbb</td><td colspan="1" valign="top">gcd</td><td colspan="1" valign="top">dba</td><td colspan="1" valign="top">bfd</td><td colspan="1" valign="top">efe</td><td colspan="1" valign="top">ede</td><td colspan="1" valign="top">bde</td><td colspan="1" valign="top">daf</td><td colspan="1" valign="top">egc</td></tr>
<tr><td colspan="1" valign="top">8</td><td colspan="1" valign="top">cbb</td><td colspan="1" valign="top">ecf</td><td colspan="1" valign="top">ddb</td><td colspan="1" valign="top">dea</td><td colspan="1" valign="top">bee</td><td colspan="1" valign="top">ccc</td><td colspan="1" valign="top">bdf</td><td colspan="1" valign="top">bdg</td><td colspan="1" valign="top">bdb</td><td colspan="1" valign="top">fbd</td><td colspan="1" valign="top">ddc</td><td colspan="1" valign="top">ade</td><td colspan="1" valign="top">eec</td><td colspan="1" valign="top">bcd</td><td colspan="1" valign="top">bbg</td><td colspan="1" valign="top">bbe</td><td colspan="1" valign="top">cfb</td><td colspan="1" valign="top">fcd</td><td colspan="1" valign="top">cfe</td><td colspan="1" valign="top">cde</td><td colspan="1" valign="top">acc</td></tr>
</table>



Первая переменная каждой тройки – выходная, вторая и третья – входные.  Для блока 4 пара переменных – входные. 

Требуется:

1)Построить граф зависимостей между блоками алгоритма.

2)Построить ярусно-параллельную форму алгоритма.

3)Найти характеристики полученной ЯПФ.

2\. Распараллеливание циклов.

`	`Дан цикл вида:

`	`For i:=max(A,B)+1 to 10 Do 

begin

`		`For j:=C+1 to 10 Do 

begin

`	 `X(i,j):=X(i-A,j)

`		 `Y(i,j):=Y(i-B,j-C)

`		`End

`	`End.

Натуральные числа А, В и С определяются в виде: А= № по журналу (mod 2)+1. В= № по журналу (mod 3)+1. C= № по журналу (mod 5)+1. Требуется:

1)Построить граф зависимостей между итерациями цикла в индексном пространстве.

2)В любом виде найти параллельную форму вычислений цикла. Представить эту форму в виде разбиения пространства итераций на минимальное число областей, содержащих независимые итерации. Выделить эти области графически в индексном пространстве. Указать порядок их выполнения, ориентируясь на ярусно-параллельную форму.

Все выполненные задания оформить в виде отчета. 

Отчет в электронном виде сдать преподавателю или направить на электронную почту director@sbmpei.ru

