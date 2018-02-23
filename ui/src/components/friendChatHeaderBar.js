import React from 'react';
import PropTypes from 'prop-types';
import { withStyles } from 'material-ui/styles';
import Grid from 'material-ui/Grid';
import AppBar from 'material-ui/AppBar';
import Toolbar from 'material-ui/Toolbar';
import Typography from 'material-ui/Typography';
import MediaAvatar from './mediaAvatar';
import MenuIcon from 'material-ui-icons/Menu';
import IconButton from 'material-ui/IconButton';
import MoreVertIcon from 'material-ui-icons/MoreVert';
import classnames from 'classnames';
import { CardHeader } from 'material-ui/Card';

const styles = theme => ({
  friendChatBarHeaderToolBar: {
    backgroundColor: theme.palette.grey.light,
    minHeight: '80px',
  },  
  friendChatBarHeaderMenuButton: {
    [theme.breakpoints.up('md')]: {
      display: 'none',
    },
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
    this.classes = props.classes;
  }

  render() {
    return (    
      <Grid item>
        <AppBar position="static" elevation={2}>
          <Toolbar className={ this.classes.friendChatBarHeaderToolBar }>
            <IconButton className={ this.classes.friendChatBarHeaderMenuButton }
              onClick={ this.props.menuButtonClickCallback }
            >
              <MenuIcon />
            </IconButton>
            <CardHeader className={ 
              classnames(this.classes.friendChatBarHeaderCardHeader, this.classes[this.props.connectionStatus + 'ConnectionStatus'])
            }
              avatar={
                <MediaAvatar
                  src={ this.props.avatarSrc }
                  char={ this.props.avatarSrc ? null : this.props.nickname.charAt(0) }
                  connectionStatus={ this.props.connectionStatus }
                />
              }
            />
            <Grid item xs zeroMinWidth>
              <Typography noWrap className={ this.classes.friendChatBarHeaderNickname }>
                { this.props.nickname }
              </Typography>
              <Typography variant="caption" noWrap gutterBottom className={ this.classes.friendChatBarHeaderStatus }>
                { this.props.statusMessage }
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
  nickname: PropTypes.string,
  statusMessage: PropTypes.string,
  avatarSrc: PropTypes.string,
  connectionStatus: PropTypes.string,
  menuButtonClickCallback: PropTypes.func,
};

FriendChatHeaderBar.defaultProps = {
  nickname: "Default nickname",
  statusMessage: "Default status message",
  avatarSrc: "",
  connectionStatus: "offline",
  menuButtonClickCallback: (() => {}),
}

export default withStyles(styles)(FriendChatHeaderBar);
