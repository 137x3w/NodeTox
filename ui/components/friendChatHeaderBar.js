import React from 'react';
import PropTypes from 'prop-types';
import { withStyles } from 'material-ui/styles';
import Grid from 'material-ui/Grid';
import AppBar from 'material-ui/AppBar';
import Toolbar from 'material-ui/Toolbar';
import Typography from 'material-ui/Typography';
import MenuIcon from 'material-ui-icons/Menu';
import Avatar from 'material-ui/Avatar';
import IconButton from 'material-ui/IconButton';
import MoreVertIcon from 'material-ui-icons/MoreVert';

import { CardHeader } from 'material-ui/Card';

const styles = theme => ({
  friendChatBarHeader: {
    minWidth: '320px',
  },
  friendChatBarHeaderToolBar: {
    backgroundColor: theme.palette.primary.contrastText,
    minHeight: '80px',
  },  
  friendChatBarHeaderMenuButton: {
    [theme.breakpoints.up('md')]: {
      display: 'none',
    },
  },
  friendChatBarHeaderCardHeader: {
  
  },
  friendChatBarHeaderAvatar: {

  },
  friendChatBarHeaderNickname: {
    fontWeight: '500',
    fontSize: '14px',
  },
  friendChatBarHeaderStatus: {
    fontWeight: '300',
  },
});

class FriendChatHeaderBar extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      mobileOpen: false,
      avatarSrc: props.avatarSrc || "",
      nickname: props.nickname || "UserUserUserUserUserUserUserUserUserUserUserUserUserUserUserUserUserUserUserUserUserUserUserUserUserUserUserUserUserUserUserUserUserUserUserUserUserUserUserUserUserUserUserUserUserUserUserUser",
      status: props.status || "User statusstatusstatusstatusstatusstatusstatusstatusstatusstatusstatusstatusstatusstatusstatusstatusstatusstatusstatusstatusstatusstatusstatusstatusstatusstatusstatusstatusstatus",
    }
    this.classes = props.classes;
  }
  
  render() {
    return (    
      <Grid item className={ this.classes.friendChatBarHeader }>
        <AppBar position="static" elevation={1}>
          <Toolbar className={ this.classes.friendChatBarHeaderToolBar }>
            <IconButton className={ this.classes.friendChatBarHeaderMenuButton }>
              <MenuIcon />
            </IconButton>
            <CardHeader className={ this.classes.friendChatBarHeaderCardHeader }
                avatar={
                  <Avatar className={ this.classes.friendChatBarHeaderAvatar } alt="User avatar" src={ this.state.avatarSrc }>
                    { this.state.avatarSrc ? null : this.state.nickname.charAt(0) }
                  </Avatar>
                }
            />
            <Grid item xs zeroMinWidth>
              <Typography noWrap gutterBottom className={ this.classes.friendChatBarHeaderNickname }>
                { this.state.nickname }
              </Typography>
              <Typography variant="caption" noWrap gutterBottom className={ this.classes.friendChatBarHeaderStatus }>
                { this.state.status }
              </Typography>
            </Grid>
            <IconButton>
              <MoreVertIcon/>
            </IconButton>
          </Toolbar>
        </AppBar>
      </Grid>
    );
  }
}

FriendChatHeaderBar.propTypes = {
  classes: PropTypes.object.isRequired,
};

export default withStyles(styles)(FriendChatHeaderBar);
