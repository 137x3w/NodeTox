import React from 'react';
import PropTypes from 'prop-types';
import { withStyles } from 'material-ui/styles';
import Grid from 'material-ui/Grid';

import SideView from './sideView';
import FriendChatView from './friendChatView';
import SettingsView from './settingsView';

import { MuiThemeProvider, createMuiTheme } from 'material-ui/styles';
import deepPurple from 'material-ui/colors/deepPurple';
import pink from 'material-ui/colors/pink';
import grey from 'material-ui/colors/grey';

const theme = createMuiTheme({
  palette: {
    primary: {
      light: deepPurple[300],
      main: deepPurple[500],
      dark: deepPurple[700],
    },
    secondary: {
      light: pink[300],
      main: pink[500],
      dark: pink[700],
    },
    grey: {
      light: grey[100],
      main: grey[500],
      dark: grey[700],
    }
  },
});

const styles = theme => ({
  appSceleton: {
    backgroundColor: grey[100],
  },
  sideBar: {},
  mainBar: {},
});

var friendsModel = {};
for(var i = 0; i < 7; i++) {
  var uid = Math.random() + "";
  friendsModel[uid] = {
    uid: uid,
    nickname: "User" + uid,
    statusMessage: "Добро пожаловать в теплую компа",
    avatarSrc: "",
    connectionStatus: "none",
    unreadMessagesCount: 2,
    messages: [],
  }
  friendsModel[uid].messages.push({
    uid: friendsModel[uid].uid,
    nickname: friendsModel[uid].nickname,
    avatarSrc: friendsModel[uid].avatarSrc,
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

var appModel = {
  profile: profileModel,
  friends: friendsModel,
}

class App extends React.Component {
  constructor(props) {
    super(props);

    this.classes = props.classes;
    this.settingsBackClickCallback = this.settingsBackClickCallback.bind(this);
    this.settingsSaveClickCallback = this.settingsSaveClickCallback.bind(this);
    this.profileBarAvatarClickCallback = this.profileBarAvatarClickCallback.bind(this);
    this.contactListItemClickCallback = this.contactListItemClickCallback.bind(this);
    this.friendChatMenuButtonClickCallback = this.friendChatMenuButtonClickCallback.bind(this);

    this.state = {
      render: {
        settings: false,
        friendChat: false,
        conferenceChat: false,
        sideBar: true,
        sideBarXs: true,
      },
      model: {
        sideView: {
          profileBar: {
            nickname: appModel.profile.nickname,
            statusMessage: appModel.profile.statusMessage,
            avatarSrc: appModel.profile.avatarSrc,
            connectionStatus: appModel.profile.connectionStatus,
            avatarClickCallback: this.profileBarAvatarClickCallback,
          },
          contactList: {
            contacts: [],
            contactListItemClickCallback: this.contactListItemClickCallback,
          },
        },
        friendChatView: {
          chatHeader: {
            menuButtonClickCallback: this.friendChatMenuButtonClickCallback,
          },
          chatBody: {
            messages: [],
          },
        },
        settingsView: {
          header: {
            backClickCallback: this.settingsBackClickCallback,
            saveClickCallback: this.settingsSaveClickCallback,
          },
          body: {
            nickname: appModel.profile.nickname,
            statusMessage: appModel.profile.statusMessage,
            toxid: appModel.profile.toxid,
            profilePassword: appModel.profile.profilePassword,
            avatarSrc: appModel.profile.avatarSrc,
          },
        },
        conferenceChatView: {
          conferenceChatHeader: {},  
        }
      }
    };

    Object.keys(appModel.friends).forEach((uid, index) => {
      this.state.model.sideView.contactList.contacts.push({
        uid: uid,
        nickname: appModel.friends[uid].nickname,
        statusMessage: appModel.friends[uid].statusMessage,
        avatarSrc: appModel.friends[uid].avatarSrc,
        connectionStatus: appModel.friends[uid].connectionStatus,
        unreadMessagesCount: appModel.friends[uid].unreadMessagesCount,
      })
    });
  }

  settingsSaveClickCallback() {

  }

  settingsBackClickCallback() {
    this.setState((prevState, props) => ({
      render: {
        settings: false,
        friendChat: false,
        conferenceChat: false,
        sideBar: prevState.render.sideBar,
        sideBarXs: prevState.render.sideBarXs,
      }
    }));
  }

  friendChatMenuButtonClickCallback() {
    this.setState((prevState, props) => ({
      render: {
        settings: false,
        friendChat: false,
        conferenceChat: false,
        sideBar: prevState.render.sideBar,
        sideBarXs: true,
      }
    }));
  }

  profileBarAvatarClickCallback() {
    this.setState((prevState, props) => ({
      render: {
        settings: true,
        friendChat: false,
        conferenceChat: false,
        sideBar: prevState.render.sideBar,
        sideBarXs: false,
      }
    }));
  }

  contactListItemClickCallback(uid) {     
    this.setState((prevState, props) => ({
      render: {
        settings: false,
        friendChat: true,
        conferenceChat: false,
        sideBar: prevState.render.sideBar,
        sideBarXs: false,
      },
      model: {
        sideView: prevState.model.sideView,
        friendChatView: {
          chatHeader: {
            nickname: appModel.friends[uid].nickname,
            statusMessage: appModel.friends[uid].statusMessage,
            avatarSrc: appModel.friends[uid].avatarSrc,
            menuButtonClickCallback: prevState.model.friendChatView.chatHeader.menuButtonClickCallback,
          },
          chatBody: {
            messages: appModel.friends[uid].messages,
          }
        },
        conferenceChatView: prevState.model.conferenceChatView,
        settingsView: prevState.model.settingsView,        
      }
    }));
  }
  
  render() {

    return (
      <MuiThemeProvider theme={theme}>
        <Grid container spacing={0} className={ this.classes.appSceleton }>
          <Grid item hidden={{ smDown: true }} md={4} lg={3} className={ this.classes.sideBar }>
            { this.state.render.sideBar &&
              (
                <SideView
                  profileBar={ this.state.model.sideView.profileBar }
                  contactList={ this.state.model.sideView.contactList }
                />
              ) 
            }
          </Grid>
          <Grid item hidden={{ mdUp: true }} xs={12} className={ this.classes.sideBar }>
            { this.state.render.sideBarXs &&
              (
                <SideView
                  profileBar={ this.state.model.sideView.profileBar }
                  contactList={ this.state.model.sideView.contactList }
                /> 
              )
            }
          </Grid>
          <Grid item xs={12} md={8} lg={9} className={ this.classes.mainBar }>
            { this.state.render.friendChat && 
              (
                <FriendChatView
                  chatHeader={ this.state.model.friendChatView.chatHeader }
                  chatBody={ this.state.model.friendChatView.chatBody }
                />
              ) 
            }

            { this.state.render.settings && 
              (
                <SettingsView
                  header={ this.state.model.settingsView.header }
                  body={ this.state.model.settingsView.body }
                />
              ) 
            }
          </Grid>
        </Grid>
      </MuiThemeProvider>
    );
  }
}

App.propTypes = {
  classes: PropTypes.object.isRequired,
};

export default withStyles(styles)(App);
