# m5stickcBugcBlynk
[M5StickC](https://www.switch-science.com/catalog/5517/)をベースとした虫型ロボット[Bugc](https://www.switch-science.com/catalog/6208/)をBlynkで操作する。BlynkのFront/Back/Left/Rightを押すとその方向に進み、スライドバーで速度が指定できる。Bugcの特性上Frontを押してもきれにまっすぐに進まないが、それらしき方向には進む。

![スクリーンショット 2021-09-26 19 08 04](https://user-images.githubusercontent.com/40074491/134803465-4effcb5c-682a-493b-b871-6d1209f349d0.png)

以下のBugcのサンプルコードリポジトリにある bugC.cpp とbugC.h を使う。
https://github.com/m5stack/M5StickC/tree/master/examples/Hat/BUGC

BlynkはLegacyではなく最新版（2021.09.26時点）を使う。最新版はAuth Tokenがアプリではなくクラウドのコンソールから入手する使用になっているので注意が必要。Blynkのダッシュボードとデータストリームは以下のように設定している。

Blynkのダッシュボード設定
![スクリーンショット 2021-09-26 18 47 49](https://user-images.githubusercontent.com/40074491/134803243-d159114d-6c0a-4a0f-83ea-b75905800d82.png)

Blynkのデータストリーム設定
![スクリーンショット 2021-09-26 19 03 23](https://user-images.githubusercontent.com/40074491/134803300-71884cdd-407a-477c-acf1-25278c40c7a4.png)

# 参照
Blynk Cloud
https://blynk.cloud

Blynk Example Browser
https://examples.blynk.cc
