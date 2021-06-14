# Task02

## 声谱图

声谱图（spectrogram）是声音或其他信号的频率随时间变化时的频谱（spectrum）的一种直观表示。声谱图有时也称sonographs,voiceprints,或者voicegrams。当数据以三维图形表示时，可称其为瀑布图（waterfalls）。在二维数组中，第一个轴是频率，第二个轴是时间。我们使用librosa.display.specshow来显示声谱图。

## 采样率

音频采样率是指录音设备在一秒钟内对声音信号的采样次数，采样频率越高声音的还原就越真实越自然。在当今的主流采集卡上，采样频率一般共分为11025Hz、22050Hz、24000Hz、44100Hz、48000Hz五个等级，11025Hz能达到AM调幅广播的声音品质，而22050Hz和24000HZ能达到[FM调频广播](https://baike.baidu.com/item/FM调频广播/13472775)的声音品质，44100Hz则是理论上的CD音质界限，48000Hz则更加精确一些。

## 波形幅度包络图

将一段时间长度的高频信号的峰值点连线，就可以得到上方（正的）一条线和下方（负的）一条线，这两条线就叫包络线。包络线就是反映高频信号幅度变化的曲线。对于等幅高频信号，这两条包络线就是平行线。





librosa学习参考: https://www.jianshu.com/p/8d6ffe6e10b9
