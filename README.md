# QPVZ
程序设计实训大作业/2016

<h1>Create</h1>
</hr>
搞了好久终于把文件都上传上去了OSZ</br>
项目开源了，大家随便看哈</br>
终于搞明白了Git和GitHub到底是啥</br>
感谢CSX，感谢廖雪峰</br>
推荐大家看一下他的网站，Git的用法说的很清楚：<a href = "http://www.liaoxuefeng.com/">廖雪峰的主页</a></br>

<h1>Update 1</h1>
时间：2016年8月30日 22:03
----------
不知不觉就把架构写完了，好开心啊</br>
接下来就是逐渐实现和完善各项功能的时候了</br>
学了Git貌似还可以顺便熟悉一下如何写HTML文档</br>
Gitpush之前一定要记得确认好自己的readme.md到底写好了没有……………………</br>

<h1>Update 2</h1>
时间：2016年9月1日 2:43
---------
MAPPING SYSTEM Finished(about 50%)</br>
一定要先在本地改好并确认好了文件再git push</br>
工作之前先记得git pull origin</br>

<h1>Update 3</h1>
时间：2016年9月1日 22:43
---------
用了真的是整整一天去写Mapping system</br>
这种小架构真是太麻烦了，好在写完了，看上去架构也合理</br>
下一次这个东西应该就可以上线了</br>

<h1>Update 4</h1>
时间：2016年9月3日 1:48
---------
调参数调了一半，现在调到种植植物的位置了</br>
真心好累啊，不过调完了应该也就差不多可以写网络组件了</br>
唉，还有SRT论文等着我呢……</br>

<h1>Update 5</h1>
时间：2016年9月4日 3:08
---------
<ol>三个BUG需要解决
	<li>植物、僵尸、子弹的位置判定不一样，采用默认的使用素材的右上角去判断会GG</li>
	<li>植物的被delete和shoot由于在不同的线程内，会导致出现冲突，可以尝试使用delelelater解决</br>
	或者设置die函数安全退出</br>
	或者参考QMyMap.cpp第170-182行与第304行的做法</br></li>
	<li>点击开始游戏的按钮会出现卡片槽不消失的情况</li>
</ol>
真心好累啊，不过调完了应该也就差不多可以写网络组件了</br>
感觉时间有点紧张了QAQ</br>

<h1>Update 6</h1>
时间：2016年9月5日 2:47
---------
<ol>实现了一些小目标
	<li>重建了对象树系统，妈妈再也不用担心我内存泄漏啦~</li>
	<li>用一种很不优雅的方式处理了多线程连续删除对象的问题</li>
	<li>可以种植植物，攻击僵尸，种植判定，有阳光了</li>
</ol>
明天一天搞定冒险模式和音乐！不能再等了！</br>
感觉时间已经很紧张了QAQ</br>

<h1>Update 7</h1>
时间：2016年9月6日 2:56
---------
<ol>实现了一些小目标
	<li>添加了铁桶僵尸和撑杆跳僵尸~</li>
	<li>添加了进度条</li>
	<li>添加了退出冒险模式的按钮，虽然因为指针bug并没有卵用，又得抱群主大腿了</li>
</ol>
居然还接了一些奇怪的锅，感觉要GG了</br>

<h1>Update 8</h1>
时间：2016年9月7日 1:25
---------
今天就做了一点小优化，以及加了开场动画，给音乐留下了时间</br>
时间都去哪了？</br>
去写SRT论文和学习QTNetwork了……</br>

<h1>Update 9</h1>
时间：2016年9月8日 1:10
---------
架构好就是好，网络一天就写完了</br>
明天加点音乐和卡片</br>
就可以去浪喽！Bravo！</br>