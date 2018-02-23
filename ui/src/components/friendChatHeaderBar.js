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
import classnames from 'classnames';
import { CardHeader } from 'material-ui/Card';

const styles = theme => ({
  friendChatBarHeader: {
    
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
    position: 'relative',
    '&:after': {
      borderRadius: '50%',
      content: "''",
      width: '10px',
      height: '10px',
      position: 'absolute',
      right: '30%',
      bottom: '10%',
    },
  },
  offlineConnectionStatus: {
    '&:after': {
      backgroundColor: "transparent",
    }
  },
  noneConnectionStatus: {
    '&:after': {
      backgroundColor: "#76FF03",
    }
  },
  awayConnectionStatus: {
    '&:after': {
      backgroundColor: "#FFEA00",
    }
  },
  busyConnectionStatus: {
    '&:after': {
      backgroundColor: "#FF3D00",
    }
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
    }
    this.classes = props.classes;
  }
  
  handleProps(props) {
    var result = {
      nickname: props.nickname || "User",
      statusMessage: props.statusMessage || "Status",
      avatarSrc: props.avatarSrc || "",
      connectionStatus: props.connectionStatus || "away",
      menuButtonClickCallback: props.menuButtonClickCallback || (() => {}),
    };
    return result;
  }

  render() {
    this.safeProps = this.handleProps(this.props);
    return (    
      <Grid item className={ this.classes.friendChatBarHeader }>
        <AppBar position="static" elevation={2}>
          <Toolbar className={ this.classes.friendChatBarHeaderToolBar }>
            <IconButton className={ this.classes.friendChatBarHeaderMenuButton }
              onClick={ this.safeProps.menuButtonClickCallback }
            >
              <MenuIcon />
            </IconButton>
            <CardHeader className={ 
              classnames(this.classes.friendChatBarHeaderCardHeader, this.classes[this.safeProps.connectionStatus + 'ConnectionStatus'])
            }
              avatar={
                <Avatar className={ this.classes.friendChatBarHeaderAvatar } alt="User avatar" src={ this.safeProps.avatarSrc }>
                  { this.safeProps.avatarSrc ? null : this.safeProps.nickname.charAt(0) }
                </Avatar>
              }
            />
            <Grid item xs zeroMinWidth>
              <Typography noWrap className={ this.classes.friendChatBarHeaderNickname }>
                { this.safeProps.nickname }
              </Typography>
              <Typography variant="caption" noWrap gutterBottom className={ this.classes.friendChatBarHeaderStatus }>
                { this.safeProps.statusMessage }
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
