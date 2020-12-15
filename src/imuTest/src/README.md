### 通信方法
無線接続の場合、ifconfig でwlanの最初のinetのipアドレスを確認する。

##### マスタ側
export ROS_MASTER_URI=http://192.168.1.41(自分のip):11311
roscore

#### ノード側
export ROS_MASTER_URI=http://192.168.1.41(自分のip):11311
export ROS_IP = 192.168.1.41(自分のip、全部のノードでやっておく)

#### 注意!
ナゼか知らんが
[registerPublisher] Failed to contact master at (マスターIP)
export ROS_MASTER_URI=http://localhost:11311
export ROS_HOSTNAME=localhost
が無いか確認。あれば消しておく。パス大嫌い！

ちなみにscpコマンドとかでファイル転送するならパッケージだけにしておく。wsごと移すとこれまたパス関係で狂う。こっちはエラー文出るけど...

### mpuUseTest.py
mpuが使えるかを試す。測定結果を表示するだけでとくにROSに関係なし。
I2C接続で
https://asukiaaa.blogspot.com/2018/04/raspberry-pi-mpu9250.html
を参考に
VCC -> 左上ピン1
GND -> 左上5番ピン9
SCL -> 左上3番ピン5
SDA -> 左上2番ピン3
に接続

### mpuPub.py, mpuDataListenerTest.cpp
mpuのデータを流し、ちゃんと流れてくるかテストで聞く