# RecursionDream
&emsp;&emsp;之前玩GaneJam大伙想到的一个游戏idea，本来打算用Unity做，但因为Unity的学生Package申请没有审批合格，而且不会Unity(捂脸)，所以用C++SFML库写了一个简单的跳格子游戏。我写的有些拉跨了，制作过于简陋。  
# Something To Say
**不可能通过同一种方法重复100次，而期望得到若干种答案**。
## 关于Release配置的一些事情
&emsp;&emsp;今天早上零点的时候我想今天花点时间配置一下把Release版本发布一下，也算是再给个小结。然而官网给的Guide巨拉跨，我有理由怀疑他都没有试过。刚开始出问题是因为Debug版本切换到release版本后，没有配置Release的Properties所以导致很多不必要的错误。这个错误也是我粗心，根本没有注意到这个事情。然后昨天的时候根据[SFMLGuide](https://www.sfml-dev.org/tutorials/2.5/start-vc.php)开始配置Release版本，又是宏又是要把依赖全部加上去，设置MT。最后发现不需要这么麻烦，所有配置只需要以下几步：  
1. Additional include Dic和Additional Library Dic设置一下。  
2. linker->Input->AddtionalDependency那里，只需要添加下面5个库的发行版本lib，根本不需要考虑静态链接什么的。  
```powershell
sfml-graphics.lib
sfml-system.lib
sfml-audio.lib
sfml-network.lib
sfml-window.lib
```
3. 把C/C++->Code Generation->Runtime Library设置成MT即可。

上述三步完成之后，直接build就完事了，这时候就不会出现一堆`LNKxxx`的Link错误。成功生成了一个exe文件，而且该exe在任何地方都可以执行。  


## 出现的一些小问题
release发布的时候，字体文件`Fonts/game.tff`为成功加载，之后再慢慢看是什么问题吧:)  