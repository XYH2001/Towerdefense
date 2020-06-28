# Towerdefense
以保卫萝卜为设计原型，以Qt为开发工具，实现有关功能。

预期功能（类似保卫萝卜）：
1.界面设计及显示：用矢量图元素绘制游戏地图及对象，同时通过按钮实现多个窗口界面的相互转换。
2.进攻者设计：设计不同类型和生命值的敌人，每关设计一定的进攻波数，不同类型敌人消失前需被攻击的次数均不同，生命值减为0的敌人从界面上消失，且可获得一定量的金币。新增“终极进攻者”（随机出现），被消灭时可增加被保护对象的生命值，但对其的攻击性能也更高；或是敌人可根据路线地形跳跃移动（随机生成）；敌人进攻完毕后被保护对象仍存活则游戏成功，弹出对话框。
3.防御者设计：设计不同类型的射手，每种射手所需的金币值不同，只有达到金币值才能使用，可升级，升级后进攻效率更高；可移除，移除时有金币奖励。新增可设在“路上”的“樱桃炸弹”（植物大战僵尸中类似的），在爆炸时能够大规模的消灭敌人。
4.被保护对象设计：设置一定的初始生命值，被进攻者攻击后生命值减少，若减为0则游戏失败，弹出对话框。
5.关卡设计：设置多个关卡，难度递增。
6.音效设计：设置游戏背景音效、被保护对象生命值减少时等事件发生音效。
7.按键功能：含暂停、二倍速功能。

目前已基本完成页面设计并能通过按钮进行页面窗口切换。