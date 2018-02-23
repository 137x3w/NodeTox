import React from 'react';
import PropTypes from 'prop-types';
import { withStyles } from 'material-ui/styles';
import { ListItem } from 'material-ui/List';
import Avatar from 'material-ui/Avatar';
import Typography from 'material-ui/Typography';
import Card, { CardContent } from 'material-ui/Card';
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
  },
  chatMessageContent: {
    padding: '16px !important',
  },
  chatMessageMessage: {
    color: theme.palette.grey.light,
    overflowX: 'auto',
  },
});

class ChatMessage extends React.Component {
  constructor(props) {
    super(props);
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
            this.props.selfMessage ? null : 
              (
                <Avatar className={ this.classes.chatMessageAvatar } alt="User avatar" src={ this.props.avatarSrc }>
                  { this.props.avatarSrc ? null : this.props.nickname.charAt(0) }
                </Avatar>
              ) 
          }
        </Grid>
        <Grid item xs={8} sm={10}>
          <Card elevation={2} className={ this.classes.chatMessageContainer }>
            <CardContent className={ this.classes.chatMessageContent }>
              <Typography noWrap className={ this.classes.chatMessageNickname }>
                { this.props.nickname }
              </Typography>
              <Typography variant="caption" noWrap gutterBottom className={ this.classes.chatMessageTime }>
                { this.formatTime(this.props.time) }
              </Typography>
              <Typography component="p" gutterBottom className={ this.classes.chatMessageMessage }>
                { this.props.message }
              </Typography>
            </CardContent>
          </Card>
        </Grid>
        <Grid item xs={2} sm={1}>
          {
            this.props.selfMessage ? 
              (
                <Avatar className={ this.classes.chatMessageAvatar } alt="User avatar" src={ this.props.avatarSrc }>
                  { this.props.avatarSrc ? null : this.props.nickname.charAt(0) }
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
  nickname: PropTypes.string,
  avatarSrc: PropTypes.string,
  message: PropTypes.string,
  time: PropTypes.number,
  selfMessage: PropTypes.bool,
};

ChatMessage.defaultProps = {
  nickname: "Default nickname",
  avatarSrc: "",
  message: "Default message",
  time: 0,
  selfMessage: false,
}

export default withStyles(styles)(ChatMessage);
