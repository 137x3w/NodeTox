import React from 'react';
import ReactDOM from 'react-dom';
import App from './components/app';

// ReactDOM.render(<ProfileBar avatarSrc="data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAADIAAAAyCAYAAAAeP4ixAAAAAXNSR0IArs4c6QAAAARnQU1BAACxjwv8YQUAAAAJcEhZcwAADsMAAA7DAcdvqGQAAAUySURBVGhD7Vlbc1NVFPa/ODwpAkUekM54mcEReVDwTZ9aHH2TYRTqX4DBGR60rRZ0QMEBx5I+KFReQIQ6+oTYC82tJE1LCE3SpmmTNM1yffuc03O6e06y907QjJOPWXPo2Xtdvn1Za++TZ+h/gg6RdkOHSLuhQ6Td0CHiRbGyTstlc4F+s2iKSDJfphOjKTr4bZwOXIjTm/zUFUev75c5ms1XbMv6MCayurZOvVeTtO3MA9r+xTS90IRAf9uZKWEPdk1gTOTK/Txt/3yadg+E6cXB5gV2YA92TWBEJFNc4+UUox39075BmQrswS7s68KASI0++y1Nz/Ho+QXTrMAu7MOPDrSJTDwuUvdQmHa1aEnJAruwDz860CJS40E6dm2ON6fsnDcsjyRkB29cb1uQoJ+jA31vG+zDD/ypQovIzXiBunjEII5TbNJXvo7SW5dmhOw/H2s4W7v6w6Kfo/My63uThuMD/lShTGSFi9Z7PyREuvQGhdTZNzpPS6V1yq5UKbpQosOXkAjcPl7B+8OXZyiaLYn+0DvB+rDj7Qc/8Ae/KlAmcvFedoszSBcvi1e/iVIkW7Z7EoXGcyJgOTXjbyypkfEndk8Seq/xjMCOty8E/uBXBUpE5nNFOsDVd2dAuoXDj68lqbZuLeoKP1HcZOLYD++HklSpWqOM/tDzGyDITh4MVP5HhcbpWInIqVspep6D8HMG6cKTR/Ruwl3TY4llq82eFTz3fBmm35NuNkJ/6An9AIHfU7/O2xrBaEjk7/QKvTQU2ZJZZMGa7r2aoLI92qgDOD85A4Dnp/y3A/RDf3nPyQK/8I846qEuEayUoz+nxJLwc7JJ7PUfmnCPGA8yJdo3FBXv952L0lRm1W4hGplctFK1tI/8BP4Rh71yfVGXyI3IklgS8qYNEgR2iNNpbrVqWyA6fecxPcsHy9O33eWR5/ZD389YRHzsyAL/iAPxBCGQSAWn2x9nAjdikKD/wJ8LG8VsbrFEH44kKZW3ZgPvB/9YUJtlj8Au4kFcfggkUuALz/7zcS5eeg6x5jEruDBZqNHUIzcJ4P3b3N5ob8iCOBAP4vJD3RnpMZkRHukBHnFnRlJLFfogNEupRevShPf9hjOCeLRnBLgR1twjPGpY+5v2yO20tUfuZOw3JNqN9gjHE4S6RJAlPvppVjlrYbmExt1KPJlZoe6zVtbqPhejyfSy3YLqn1XPWtzvKMdhnLWA+5y/9yrUEZBFNS+vWbOBJSTXkb7RWdEGoF/v8EOlOrKXj/V/zdc/QDYkApzkyuoE5CeYdjzHEm7VHkv6VfaIqPgO7j4s0J7ByEYfP4Hfk7eQuutMB0OJCM469c5acPbJdbdq4yx1BGctiTyWyBE+a6151gj0ggYJ/uC3ZWct4OK9nG8Gw2ji9Bt+4lbt0GRerP/dUt+N0y+3O4jwsR/6frMCf/CrAmUi+Ij27pWtZyP8jb1QKFdFNorxsVxkpIDZA5F3uD3O/dC/UKoKfT+78Kf68U6ZCHAzxjdEduJNx/g/bogochBxQwy4VDmC4vY693N0oC/bhB/4U4UWkRr/O3adD5H/xp2d/cCfKrSIABPpInV/heA3B9YqEV9R2D786ECbCOYF1fppfteC/UbpVoYBEXxprNLB7+KBG9pUxJdGtgv7ujAiAlx+St9+YdcExkTwmaZnuLVf43uG1T//yDAmAiRyZTrO2QW/b7xxwfqtQ1eEHusf51qS/C9+H/EClyVceEzFvYSZoyVE2gEdIu2GDpF2Q4dIe4HoH2zLojP/hs3LAAAAAElFTkSuQmCC" nickname="dratuti" status="My status" avatarClickCallback={ () => { console.log("test"); } }/>, document.querySelector('#root'));

function uuidv4() {
  return ([1e7]+-1e3+-4e3+-8e3+-1e11).replace(/[018]/g, c =>
  	// Replace crypto on sodium
    (c ^ crypto.getRandomValues(new Uint8Array(1))[0] & 15 >> c / 4).toString(16)
  )
}

// Creating app model
var friendsModel = {};
for(var i = 0; i < 7; i++) {
	var uid = uuidv4();
	friendsModel[uid] = {
		uid: uid,
		nickname: "User" + uid,
		statusMessage: "Добро пожаловать в теплую компа",
		avatarSrc: "",
		connectionStatus: "none",
		unreadMessagesCount: 2000,
		messages: [],
	}
	friendsModel[uid].messages.push({
		uid: friendsModel[uid].uid,
		time: 0,
		message: "mes1"+uid,
	});
}

var profileModel = {
	nickname: "SelfNick",
	statusMessage: "SelfStatus",
	avatarSrc: "",
	connectionStatus: "away",
	toxid: "DD",
	profilePassword: "",
}

var friendRequests = {};
for(var i = 0; i < 7; i++) {
	var uid = uuidv4();
	friendRequests[uid] = {
		uid: uid,
		toxid: "DD5149809F2320BC81215D2A363A95778D39A0BC260BE7DC90923A933552C765A21E305E722C",
		message: "gfgffffffffff",
		time: 0
	}
}

var appModel = {
	profile: profileModel,
	friends: friendsModel,
	friendRequests: friendRequests,
}
//

// View template
var view = {
	sideView: {
		profileBar: {
			nickname: appModel.profile.nickname,
			statusMessage: appModel.profile.statusMessage,
			avatarSrc: appModel.profile.avatarSrc,
			connectionStatus: appModel.profile.connectionStatus,
		},
		contactList: {
			contacts: [
				{
					uid: "0",
					nickname: "",
					statusMessage: "",
					avatarSrc: "",
					connectionStatus: "",
					unreadMessagesCount: 0,
				},
			],
		},
	},
	friendChatView: {
		header: {
			avatarSrc: "",
			nickname: "",
			statusMessage: "",
			connectionStatus: "",
		},
		body: {
			messages: [
				{
					uid: "",
					nickname: "",
					avatarSrc: "",
					message: "",
					time: 0,
					selfMessage: false,
				},
			],
		},
	},
	conferenceChatView: {
		body: {
			messages: [],
		},
	},
	dashboardView: {          
		body: {
			settings: {
				nickname: appModel.profile.nickname,
				statusMessage: appModel.profile.statusMessage,
				toxid: appModel.profile.toxid,
				profilePassword: appModel.profile.profilePassword,
				avatarSrc: appModel.profile.avatarSrc,
			},
			friendsControl: {
				friendRequests: [
					{
						uid: "",
						toxid: "",
						message: "",
						time: 0,
					}
				],
			},
			groupsControl: {
				groupRequests: [
					{
						uid: "",
						nickname: "",
						time: 0,
					}
				]
			},
			filesControl: {

			},
		},
	},
}

view.sideView.contactList.contacts.pop();
Object.keys(appModel.friends).forEach((uid, index) => {
	view.sideView.contactList.contacts.push({
		uid: uid,
		nickname: appModel.friends[uid].nickname,
		statusMessage: appModel.friends[uid].statusMessage,
		avatarSrc: appModel.friends[uid].avatarSrc,
		connectionStatus: appModel.friends[uid].connectionStatus,
		unreadMessagesCount: appModel.friends[uid].unreadMessagesCount,
	});
});

view.dashboardView.body.friendsControl.friendRequests.pop();
Object.keys(appModel.friendRequests).forEach((uid, index) => {
	view.dashboardView.body.friendsControl.friendRequests.push({
		uid: uid,
		toxid: appModel.friendRequests[uid].toxid,
		message: appModel.friendRequests[uid].message,
		time: appModel.friendRequests[uid].time,
	})
});

function newFriendChatView(friendUid) {
	var friend = appModel.friends[friendUid];

	view.friendChatView.header = {};
	view.friendChatView.body.messages = [];

	view.friendChatView.header = {
		avatarSrc: friend.avatarSrc,
		nickname: friend.nickname,
		statusMessage: friend.statusMessage,
		connectionStatus: friend.connectionStatus,
	};

	friend.messages.forEach(function(msg, msgIndex) {
		view.friendChatView.body.messages.push({
			friendUid: msg.friendUid,
			nickname: friend.nickname,
			avatarSrc: friend.avatarSrc,
			message: msg.message,
			time: msg.time,
			selfMessage: false,
		});
	});
}

function renderView(view) {
	ReactDOM.render(<App 
						view={ view }
						newFriendChatView={ newFriendChatView }
					/>, document.querySelector('#root'));
}

renderView(view);