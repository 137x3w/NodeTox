import React from 'react';
import PropTypes from 'prop-types';
import { withStyles } from 'material-ui/styles';
import { ListItem } from 'material-ui/List';
import Typography from 'material-ui/Typography';
import Card, { CardContent, CardActions } from 'material-ui/Card';
import Grid from 'material-ui/Grid';
import Button from 'material-ui/Button';

const styles = theme => ({
  chatMessage: {
    overflow: 'hidden',
    alignItems: 'flex-start',
    paddingLeft: '0',
    paddingRight: '0',
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
    paddingBottom: '0',
  },
  chatMessageMessage: {
    color: theme.palette.grey.light,
    overflowX: 'auto',
  },
});

class RequestMessage extends React.Component {
  constructor(props) {
    super(props);
    this.classes = props.classes;

    this.handleAllowRequest = this.handleAllowRequest.bind(this);
    this.handleDenyRequest = this.handleDenyRequest.bind(this);
  }

  formatTime(unixTime) {
    return unixTime;
  }

  handleAllowRequest = function() {
    this.props.allowRequestCallback(this.props.uid);
  }

  handleDenyRequest = function() {
    this.props.denyRequestCallback(this.props.uid);
  }
  
  render() {
    return (    
      <ListItem className={this.classes.chatMessage}>
        <Grid item xs={1}/>
        <Grid item xs={10}>
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
            <CardActions>
              <Button 
                color="secondary"
                onClick={ this.handleAllowRequest }
              >
                Allow
              </Button>
              <Button 
                color="secondary"
                onClick={ this.handleDenyRequest }
              >
                Deny
              </Button>
            </CardActions>
          </Card>
        </Grid>
        <Grid item xs={1}/>
      </ListItem>
    );
  }
}

RequestMessage.propTypes = {
  classes: PropTypes.object.isRequired,
  uid: PropTypes.string,
  nickname: PropTypes.string,
  message: PropTypes.string,
  time: PropTypes.number,
  allowRequestCallback: PropTypes.func,
  denyRequestCallback: PropTypes.func,
};

RequestMessage.defaultProps = {
  uid: "0",
  nickname: "Default nickname",
  message: "Default message",
  time: 0,
  allowRequestCallback: (() => {}),
  denyRequestCallback: (() => {}),
}

export default withStyles(styles)(RequestMessage);
