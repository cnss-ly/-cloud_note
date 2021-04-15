# Task01

## 一些音频相关知识

### 信号

信号是一定量随时间的变化。 对于音频，变化的量是气压。 我们如何以数字方式捕获此信息？ 我们可以随时间采集气压样本。 我们采样数据的速率可以变化，但是最常见的是44.1kHz，即每秒44,100个采样。 我们捕获的是信号的波形，可以使用计算机软件对其进行解释，修改和分析。

### 傅立叶变换

音频信号由几个单频声波组成。 在一段时间内对信号进行采样时，我们仅捕获得到的幅度。 傅立叶变换是一个数学公式，它使我们可以将信号分解为单个频率和频率幅度。 换句话说，它将信号从时域转换到频域。 结果称为频谱。

这是可能的，因为每个信号都可以分解为一组正弦波和余弦波，它们加起来等于原始信号。 这是一个著名的定理，称为傅立叶定理。

快速傅立叶变换（FFT）是一种可以有效计算傅立叶变换的算法。 它广泛用于信号处理。 我将在示例音频的窗口片段中使用此算法。

### 频谱图

快速傅立叶变换是一种功能强大的工具，可让我们分析信号的频率成分，但是如果信号的频率成分随时间变化，该怎么办？ 大多数音频信号（例如音乐和语音）就是这种情况。 这些信号称为非周期性信号。 我们需要一种表示这些信号随时间变化的频谱的方法。 您可能会想，“嘿，我们不能通过对信号的多个窗口部分执行FFT来计算多个频谱吗？” 是! 这正是完成的工作，称为短时傅立叶变换。 FFT是在信号的重叠窗口部分上计算的，我们得到了所谓的频谱图。 哇！ 需要接受很多东西。这里有很多事情要做。 良好的视觉效果是必须的。

您可以将频谱图视为一堆相互堆叠的FFT。 当信号在不同频率下随时间变化时，这是一种直观地表示信号响度或幅度的方法。 计算频谱图时，还有一些其他细节。 y轴转换为对数刻度，颜色尺寸转换为分贝（您可以将其视为振幅的对数刻度）。 这是因为人类只能感知到非常小的集中频率和幅度范围。

### 梅尔（Mel）量表

研究表明，人类不会感知线性范围的频率。 我们在检测低频差异方面要胜于高频。 例如，我们可以轻松分辨出500 Hz和1000 Hz之间的差异，但是即使之间的距离相同，我们也很难分辨出10,000 Hz和10,500 Hz之间的差异。

1937年，Stevens，Volkmann和Newmann提出了一个音高单位，以使相等的音高距离听起来与听众相等。 这称为梅尔音阶。 我们对频率执行数学运算，以将其转换为mel标度。

### Mel谱图

mel谱图是频率转换为mel标度的谱图。使用python的librosa音频处理库它只需要几行代码就可以实现。

### librosa

librosa是一个非常强大的python语音信号处理的第三方库.

### 其他

一些语音信号专业名词：sr：采样率、hop_length：帧移、overlapping：连续帧之间的重叠部分、n_fft：窗口大小、spectrum：频谱、spectrogram：频谱图或叫做语谱图、amplitude：振幅、mono：单声道、stereo：立体声

## librosa使用

```python
#首先是读取音频
librosa.load(path, sr=22050, mono=True, offset=0.0, duration=None)
#读取音频文件。默认采样率是22050，如果要保留音频的原始采样率，使用sr = None.
#param:
	#path ：音频文件的路径。
	#sr ：采样率，如果为“None”使用音频自身的采样率
	#mono ：bool，是否将信号转换为单声道
	#offset ：float，在此时间之后开始阅读（以秒为单位）
	#持续时间：float，仅加载这么多的音频（以秒为单位）
#return:
	#y ：音频时间序列
	#sr ：音频的采样率
```

```python
#Mel滤波器
librosa.filters.mel(sr, n_fft, n_mels=128, fmin=0.0, fmax=None, htk=False, norm=1)
#创建一个滤波器组矩阵以将FFT合并成Mel频率
#param：
	#sr ：输入信号的采样率
	#n_fft ：FFT组件数
	#n_mels ：产生的梅尔带数
	#fmin ：最低频率（Hz）
	#fmax：最高频率（以Hz为单位）。如果为None，则使用fmax = sr / 2.0
	#norm：{None，1，np.inf} [标量]
	#如果为1，则将三角mel权重除以mel带的宽度（区域归一化）。否则，保留所有三角形的峰值为1.0
#return：
	#Mel变换矩阵
```

## baseline1-CNN

baseline1比较简单,思路为将音频文件转化为mel矩阵作为特征输入cnn网络.

运行成功

## baseline2-LSTM

### LSTM理解

#### 短时记忆

NN 会受到短时记忆的影响。如果一条序列足够长，那它们将很难将信息从较早的时间步传送到后面的时间步。 因此，如果你正在尝试处理一段文本进行预测，RNN 可能从一开始就会遗漏重要信息。

在反向传播期间，RNN 会面临梯度消失的问题。 梯度是用于更新神经网络的权重值，消失的梯度问题是当梯度随着时间的推移传播时梯度下降，如果梯度值变得非常小，就不会继续学习。

因此，在递归神经网络中，获得小梯度更新的层会停止学习—— 那些通常是较早的层。 由于这些层不学习，RNN 可以忘记它在较长序列中看到的内容，因此具有短时记忆。

LSTM 是一种解决短时记忆问题的解决方案，它们具有称为“门”的内部机制，可以调节信息流,可以知道序列中哪些重要的数据是需要保留，而哪些是要删除的。

RNN 将先前隐藏状态传递给序列的下一步, 而**隐藏状态充当了神经网络记忆**，它包含相关网络之前所见过的数据的信息。

#### 核心概念

LSTM 的核心概念在于细胞状态以及“门”结构。细胞状态相当于信息传输的路径，让信息能在序列连中传递下去。你可以将其看作网络的“记忆”。理论上讲，细胞状态能够将序列处理过程中的相关信息一直传递下去。

因此，即使是较早时间步长的信息也能携带到较后时间步长的细胞中来，这克服了短时记忆的影响。信息的添加和移除我们通过“门”结构来实现，“门”结构在训练过程中会去学习该保存或遗忘哪些信息。

门结构中包含着 sigmoid 激活函数,把值压缩到 0~1 之间.因为任何数乘以 0 都得 0，这部分信息就会剔除掉。同样的，任何数乘以 1 都得到它本身，这部分信息就会完美地保存下来。

#### LSTM 有三种类型的门结构：遗忘门、输入门和输出门

**遗忘门**

 遗忘门的功能是决定应丢弃或保留哪些信息。来自前一个隐藏状态的信息和当前输入的信息同时传递到 sigmoid 函数中去，输出值介于 0 和 1 之间，越接近 0 意味着越应该丢弃，越接近 1 意味着越应该保留。

![640?wx_fmt=gif](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9tbWJpei5xcGljLmNuL21tYml6X2dpZi9CblNORWFmaWNGQWIxaDZOQ28wNWF0Qlh2ZHU3UThQaWJwbURHVmljTHhVRGRVYlhsUmF5Tm9NUzZUU3dsUE5CYW1vNVR1WlBLWlpFVDdoZ2ZYUGJXZ1pQZy82NDA_d3hfZm10PWdpZg?x-oss-process=image/format,png)

**输入门**

输入门用于更新细胞状态。首先将前一层隐藏状态的信息和当前输入的信息传递到 sigmoid 函数中去。将值调整到 0~1 之间来决定要更新哪些信息。0 表示不重要，1 表示重要。

其次还要将前一层隐藏状态的信息和当前输入的信息传递到 tanh 函数中去，创造一个新的侯选值向量。最后将 sigmoid 的输出值与 tanh 的输出值相乘，sigmoid 的输出值将决定 tanh 的输出值中哪些信息是重要且需要保留下来的。

**细胞状态**

下一步，就是计算细胞状态。首先前一层的细胞状态与遗忘向量逐点相乘。如果它乘以接近 0 的值，意味着在新的细胞状态中，这些信息是需要丢弃掉的。然后再将该值与输入门的输出值逐点相加，将神经网络发现的新信息更新到细胞状态中去。至此，就得到了更新后的细胞状态。

![640?wx_fmt=gif](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9tbWJpei5xcGljLmNuL21tYml6X2dpZi9CblNORWFmaWNGQWIxaDZOQ28wNWF0Qlh2ZHU3UThQaWJwdE1pYkx1NDFGWjhNaWJZU3RiaEg2WU93MlFEUzNPY25aYmtZNkpEa3ZwZXJndXdlVndSMVR2aWFBLzY0MD93eF9mbXQ9Z2lm?x-oss-process=image/format,png)

**输出门**

输出门用来确定下一个隐藏状态的值，隐藏状态包含了先前输入的信息。首先，我们将前一个隐藏状态和当前输入传递到 sigmoid 函数中，然后将新得到的细胞状态传递给 tanh 函数。

最后将 tanh 的输出与 sigmoid 的输出相乘，以确定隐藏状态应携带的信息。再将隐藏状态作为当前细胞的输出，把新的细胞状态和新的隐藏状态传递到下一个时间步长中去。

输入门确定当前输入中哪些信息是重要的，需要被添加的；输出门确定下一个隐藏状态应该是什么。

![640?wx_fmt=gif](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9tbWJpei5xcGljLmNuL21tYml6X2dpZi9CblNORWFmaWNGQWIxaDZOQ28wNWF0Qlh2ZHU3UThQaWJwSW9ZaENOVHp1YVM0WGNQb3Nnb1c2b3dkZ0VlUFJibm5BbzVaaWNpYmMyV1pVcUNLR0RpYmRxUXZ3LzY0MD93eF9mbXQ9Z2lm?x-oss-process=image/format,png)

资料来源

https://www.cnblogs.com/LXP-Never/p/11561355.html

https://zhuanlan.zhihu.com/p/198900624

https://blog.csdn.net/yingqubaifumei/article/details/100888147

