import React from 'react';
import PropTypes from 'prop-types';
import { withStyles } from 'material-ui/styles';
import { ListItem } from 'material-ui/List';
import Avatar from 'material-ui/Avatar';
import Typography from 'material-ui/Typography';
import Icon from 'material-ui/Icon';
import RepeatIcon from 'material-ui-icons/Repeat';
import Badge from 'material-ui/Badge';
import Card, { CardContent, CardActions } from 'material-ui/Card';
import Grid from 'material-ui/Grid';

const styles = theme => ({
  chatMessage: {
    overflow: 'hidden',
    alignItems: 'flex-start',
    paddingLeft: '0',
    paddingRight: '0',
  },
  chatMessageAvatar: {
    width: '30px',
    height: '30px',
    margin: '0 auto',
    marginTop: '15px',
    backgroundColor: theme.palette.secondary.main,
  },
  chatMessageNickname: {
    color: theme.palette.grey.light,
    fontWeight: '500',
  },
  chatMessageTime: {
    color: theme.palette.primary.contrastText,
    fontWeight: '300',
  },
  chatMessageContainer: {
    backgroundColor: theme.palette.primary.main,
    // margin: '0 0 0 auto',
  },
  chatMessageContent: {
    padding: '16px !important',
  },
  chatMessageMessage: {
    color: theme.palette.grey.light,
    overflowX: 'auto',
  },
  chatMessageRepeat: {
    color: theme.palette.grey.light,
    fontWeight: '100',
  },
});

class ChatMessage extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      nickname: props.nickname || "User",
      avatarSrc: props.avatarSrc || "",
      message: props.message || "",
      time: props.time || 0,
      selfMessage: props.selfMessage || false,
      repeatedMessageCount: props.repeatedMessageCount || 0,
    }
    this.classes = props.classes;
  }

  formatTime(unixTime) {
    return unixTime;
  }
  
  render() {
    return (    
      <ListItem className={this.classes.chatMessage}>
        <Grid item xs={2} sm={1}>
          {
            this.state.selfMessage ? null : 
              (
                <Avatar className={ this.classes.chatMessageAvatar } alt="User avatar" src={ this.state.avatarSrc }>
                  { this.state.avatarSrc ? null : this.state.nickname.charAt(0) }
                </Avatar>
              ) 
          }
        </Grid>
        <Grid item xs={8} sm={10}>
          <Card elevation={2} className={ this.classes.chatMessageContainer }>
            <CardContent className={ this.classes.chatMessageContent }>
              <Typography noWrap className={ this.classes.chatMessageNickname }>
                { this.state.nickname }
              </Typography>
              <Typography variant="caption" noWrap gutterBottom className={ this.classes.chatMessageTime }>
                { this.formatTime(this.state.time) }
              </Typography>
              <Typography component="p" gutterBottom className={ this.classes.chatMessageMessage }>
                { this.state.message }
              </Typography>
              {
                this.state.repeatedMessageCount > 0 ? 
                (
                  <Typography variant="caption" noWrap className={ this.classes.chatMessageRepeat }>
                    {`x${ this.state.repeatedMessageCount }`}
                  </Typography>
                ) : null
              }
            </CardContent>
          </Card>
        </Grid>
        <Grid item xs={2} sm={1}>
          {
            this.state.selfMessage ? 
              (
                <Avatar className={ this.classes.chatMessageAvatar } alt="User avatar" src={ this.state.avatarSrc }>
                  { this.state.avatarSrc ? null : this.state.nickname.charAt(0) }
                </Avatar>
              ) : null
          }
        </Grid>
        
      </ListItem>
    );
  }
}

ChatMessage.propTypes = {
  classes: PropTypes.object.isRequired,
};

export default withStyles(styles)(ChatMessage);
