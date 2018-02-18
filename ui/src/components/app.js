import React from 'react';
import PropTypes from 'prop-types';
import { withStyles } from 'material-ui/styles';
import Grid from 'material-ui/Grid';
import ProfileBar from './profileBar';
import ContactListBar from './contactListBar';
import FriendChatHeaderBar from './friendChatHeaderBar';
import ChatTextInputBar from './chatTextInputBar';
import ChatBodyBar from './chatBodyBar';
import ProfileSettingsBody from './profileSettingsBody';
import ProfileSettingsHeader from './profileSettingsHeader';

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
    
  },
  sideBar: {
    // backgroundColor: grey[100],
  },
  mainBar: {
    backgroundColor: grey[100],
  }
});

var contactsModel = 
[
  {
    nickname: "111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111",
    statusMessage: "1",
    avatarSrc: "",
    connectionStatus: 1,
    unreadMessagesCount: 3,
  },
  {
    nickname: "1",
    statusMessage: "1",
    avatarSrc: "",
    connectionStatus: 1,
    unreadMessagesCount: 3,
  },
  {
    nickname: "1",
    statusMessage: "1",
    avatarSrc: "",
    connectionStatus: 1,
    unreadMessagesCount: 3,
  },
  {
    nickname: "1",
    statusMessage: "1",
    avatarSrc: "",
    connectionStatus: 1,
    unreadMessagesCount: 3,
  },
  {
    nickname: "1",
    statusMessage: "1",
    avatarSrc: "",
    connectionStatus: 1,
    unreadMessagesCount: 3,
  },
  {
    nickname: "1",
    statusMessage: "1",
    avatarSrc: "",
    connectionStatus: 1,
    unreadMessagesCount: 3,
  },
  {
    nickname: "1",
    statusMessage: "1",
    avatarSrc: "",
    connectionStatus: 1,
    unreadMessagesCount: 3,
  }
];

var messagesModel =
[
  {
    nickname: "1",
    avatarSrc: "",
    time: 0,
    message: "aaaaaaaaaaaaaaaaaaaaaa aaaaaaaaaaaaaaaaaaaaaadfgdfgsf sdgsfsaaaaaaaaa aaaaaaaaaaaaaaaaaa aaaaaaaaaaaaaaa aaaaaaaaaaaaaa",
    selfMessage: true,
    repeatedMessageCount: 1,
  },
  {
    nickname: "1",
    avatarSrc: "",
    time: 0,
    message: "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
  },
  {
    nickname: "1",
    avatarSrc: "",
    time: 0,
    message: "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
  },
  {
    nickname: "1",
    avatarSrc: "",
    time: 0,
    message: "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
  },
  {
    nickname: "1",
    avatarSrc: "",
    time: 0,
    message: "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
  }
]

contactsModel.map((item, index) => {
  contactsModel[index].uid = {};
  contactsModel[index].uid = Math.random() + "";
});

messagesModel.map((item, index) => {
  messagesModel[index].uid = {};
  messagesModel[index].uid = Math.random() + "";
})

class App extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      render: {
        settings: true,
        friendChat: false,
        sideBar: true,
      }
    };
    this.classes = props.classes;
    this.settingsBackClickCallback = this.settingsBackClickCallback.bind(this);
    this.profileBarAvatarClickCallback = this.profileBarAvatarClickCallback.bind(this);
  }

  settingsSaveClickCallback() {

  }

  settingsBackClickCallback() {
    this.setState({
      render: {
        settings: false,
        friendChat: true,
        sideBar: true,
      }
    });
  }

  profileBarAvatarClickCallback() {
    this.setState({
      render: {
        settings: true,
        friendChat: false,
        sideBar: true,
      }
    }); 
  }
  
  render() {
    return ( 
      <MuiThemeProvider theme={theme}>
        <Grid container spacing={0} className={ this.classes.appSceleton }>
          <Grid item hidden={{ smDown: true }} md={4} lg={3} className={ this.classes.sideBar }>
            { this.state.render.sideBar && 
              (
                <ProfileBar connectionStatus="busy" avatarClickCallback={ this.profileBarAvatarClickCallback }/>
              ) 
            }
            { this.state.render.sideBar && 
              (
                <ContactListBar contacts={ contactsModel }/>
              ) 
            }
          </Grid>
          <Grid item xs={12} md={8} lg={9} className={ this.classes.mainBar }>
            { this.state.render.friendChat && 
              (
                <FriendChatHeaderBar/>
              ) 
            }
            { this.state.render.friendChat && 
              (
                <ChatBodyBar messages={ messagesModel }/>
              ) 
            }
            { this.state.render.friendChat && 
              (
                <ChatTextInputBar/>
              ) 
            }
            { this.state.render.settings && 
              (
                <ProfileSettingsHeader backClickCallback={ this.settingsBackClickCallback } saveClickCallback={ this.settingsSaveClickCallback }/>
              ) 
            }
            { this.state.render.settings && 
              (
                <ProfileSettingsBody/>
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
