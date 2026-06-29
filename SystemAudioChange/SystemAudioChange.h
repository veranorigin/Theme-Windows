/*
contributers:Su Yu Ning
date:2026-6-25
*/
#pragma once

#include<iostream>
#include<vector>
#include<windows.h>
#include"RegistryChange.h"
struct SysAudioList {
	/*
	  Well,i think all system audio you'd want to change are here.
	  Routes will be restored here.
	  Also,you can change them in the system settings.
	  Reference to https://space.bilibili.com/31436472/lists/7651464?type=season,本当にありがとう。
	 */
	std::wstring _point_Default;//默认声响
	std::wstring CriticalBatteryAlarm;//电池严重短缺警报
	std::wstring DeviceConnect;//设备连接
	std::wstring DeviceDisconnect;//设备中断连接
	std::wstring DeviceFail;//设备未能连接
	std::wstring FaxBeep;//新传真通知
	std::wstring LowBatteryAlarm;//电池不足警报
	std::wstring MailBeep;//桌面邮件通知
	std::wstring MessageNudge;//消息闪屏振动
	std::wstring Notification_point_Default;//通知
	std::wstring Notification_point_IM;//即时消息通知
	std::wstring Notification_point_Mail;//新邮件通知
	std::wstring Notification_point_Proximity;//NFP完成
	std::wstring Notification_point_Reminder;//日历提醒
	std::wstring Notification_point_SMS;//新短信通知
	std::wstring ProximityConnection;//NFP连接
	std::wstring SystemAsterisk;//星号
	std::wstring SystemExclamation;//感叹号
	std::wstring SystemHand;//关键性停止
	std::wstring SystemNotification;//系统通知
	std::wstring WindowsUAC;//用户账户控制
};

class SystemAudioChange:public RegistryChange {
	SysAudioList to_change_list;//外界会向这个类传递一个“sysaudiolist”结构体，按照那里面的地址修改注册表即可。
	int num;//关于我们已经向注册表插入了多少数据这回事。
	std::vector<std::wstring> changed_list;//因为reset函数的需要，如果能够随时取消之前做过的改动会比较好，因此存储.current键的数据是必要的。
	//以下都是我们在处理两个对外接口的实现时可能会用到的函数吧。
	int SoloChange(std::wstring key,std::wstring value,HKEY);
public:
	SystemAudioChange(SysAudioList waiting_list,int x):RegistryChange(),to_change_list(waiting_list),num(x) {
	}
	~SystemAudioChange() {	
	}
	int do_the_change() override;
	int reset() override;
};
