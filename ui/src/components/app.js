import React from 'react';
import PropTypes from 'prop-types';
import { withStyles } from 'material-ui/styles';
import Grid from 'material-ui/Grid';

import SideView from './sideView';
import FriendChatView from './friendChatView';
import DashboardView from './dashboardView';

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
});

class App extends React.Component {
  constructor(props) {
    super(props);
    this.classes = props.classes;

    this.settingsSaveClickCallback = this.settingsSaveClickCallback.bind(this);
    this.profileBarClickCallback = this.profileBarClickCallback.bind(this);
    this.contactClickCallback = this.contactClickCallback.bind(this);
    this.contactsTabClickCallbackSm = this.contactsTabClickCallbackSm.bind(this);
    this.friendChatMenuButtonClickCallback = this.friendChatMenuButtonClickCallback.bind(this);

    this.state = {
      render: {
        default: {
          dashboard: true,
          friendChat: false,
          conferenceChat: false,
          sideBar: true,
        },
        small: {
          dashboard: false,
          friendChat: false,
          conferenceChat: false,
          sideBar: true,
        },
      },
    };
  }

  contactsTabClickCallbackSm() {
    this.setState((prevState, props) => ({
      render: {
        default: {
          dashboard: true,
          friendChat: false,
          conferenceChat: false,
          sideBar: prevState.render.default.sideBar,
        },
        small: {
          dashboard: false,
          friendChat: false,
          conferenceChat: false,
          sideBar: true,
        }
      }
    }));
  }

  settingsSaveClickCallback() {

  }

  friendChatMenuButtonClickCallback() {
    this.setState((prevState, props) => ({
      render: {
        default: {
          dashboard: true,
          friendChat: false,
          conferenceChat: false,
          sideBar: prevState.render.default.sideBar,  
        },
        small: {
          dashboard: false,
          friendChat: false,
          conferenceChat: false,
          sideBar: true,
        }
      }
    }));
  }

  profileBarClickCallback() {
    this.setState((prevState, props) => ({
      render: {
        default: {
          dashboard: true,
          friendChat: false,
          conferenceChat: false,
          sideBar: prevState.render.default.sideBar,
        },
        small: {
          dashboard: true,
          friendChat: false,
          conferenceChat: false,
          sideBar: false,
        }
      }
    }));
  }

  contactClickCallback(friendUid) {
    this.props.handleOpenFriendChatView(friendUid);
    this.setState((prevState, props) => ({
      render: {
        default: {
          dashboard: false,
          friendChat: true,
          conferenceChat: false,
          sideBar: prevState.render.default.sideBar,
        },
        small: {
          dashboard: false,
          friendChat: true,
          conferenceChat: false,
          sideBar: false,
        },
      },
    }));
  }
  
  render() {
    return (
      <MuiThemeProvider theme={theme}>
        <Grid container spacing={0} className={ this.classes.appSceleton }>
          { this.state.render.small.sideBar &&
            (
              <Grid item hidden={{ mdUp: true }} xs={12}>
                <SideView
                  profileBar={ this.props.view.sideView.profileBar }
                  profileBarClickCallback={ this.profileBarClickCallback }
                  contactList={ this.props.view.sideView.contactList }
                  contactListItemClickCallback={ this.contactClickCallback }
                /> 
              </Grid>
            )
          }
          { this.state.render.default.sideBar &&
            (<Grid item hidden={{ smDown: true }} md={4} lg={3}>
                <SideView
                  profileBar={ this.props.view.sideView.profileBar }
                  profileBarClickCallback={ this.profileBarClickCallback }
                  contactList={ this.props.view.sideView.contactList }
                  contactListItemClickCallback={ this.contactClickCallback }
                />
            </Grid>)
          }
          <Grid item hidden={{ mdUp: true }} xs={12}>
            { this.state.render.small.dashboard && 
              (
                <DashboardView
                  contactsClickCallback={ this.contactsTabClickCallbackSm }
                  dashboardBody={ this.props.view.dashboardView.body }
                />
              ) 
            }
            { this.state.render.small.friendChat && 
              (
                <FriendChatView
                  friendChatView={ this.props.view.friendChatView }
                  menuButtonClickCallback={ this.friendChatMenuButtonClickCallback }
                />
              ) 
            }
            { this.state.render.small.conferenceChat && 
              (
                <FriendChatView
                  chatHeader={ this.props.view.friendChatView.header }
                  menuButtonClickCallback={ this.chatMenuButtonClickCallback }
                  chatBody={ this.props.view.friendChatView.body }
                />
              ) 
            }
          </Grid>
          <Grid item hidden={{ smDown: true }} md={8} lg={9}>
            { this.state.render.default.dashboard && 
              (
                <DashboardView
                  contactsClickCallback={ this.contactsTabClickCallbackSm }
                  dashboardBody={ this.props.view.dashboardView.body }
                />
              ) 
            }
            { this.state.render.default.friendChat && 
              (
                <FriendChatView
                  friendChatView={ this.props.view.friendChatView }
                  menuButtonClickCallback={ this.friendChatMenuButtonClickCallback }
                />
              ) 
            }
            { this.state.render.default.conferenceChat && 
              (
                <FriendChatView
                  chatHeader={ this.props.view.friendChatView.header }
                  menuButtonClickCallback={ this.chatMenuButtonClickCallback }
                  chatBody={ this.props.view.friendChatView.body }
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
  view: PropTypes.object,
  handleOpenFriendChatView: PropTypes.func,
};

App.defaultProps = {
  handleOpenFriendChatView: ((friendUid) => {}),
};

export default withStyles(styles)(App);
