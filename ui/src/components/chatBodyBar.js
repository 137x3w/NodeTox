import React from 'react';
import PropTypes from 'prop-types';
import { withStyles } from 'material-ui/styles';
import Grid from 'material-ui/Grid';
import List from 'material-ui/List';
import ChatMessage from './chatMessage';

const styles = theme => ({
  chatBodyBar: {
    overflow: 'auto',
    height: 'calc(100vh - 160px)',
  },
  chatBodyBarMessagesList: {

  },
});

class ChatBodyBar extends React.Component {
  constructor(props) {
    super(props);
    this.state = {};
    this.classes = props.classes;
  }

  handleProps(props) {
    var result = {
      messages: props.messages || [],
    };
    return result;
  }
  
  render() {
    this.safeProps = this.handleProps(this.props);
    return (    
      <Grid item className={ this.classes.chatBodyBar }>
        <List className={ this.classes.chatBodyBarMessagesList }>
          {
            this.safeProps.messages.map((item) => (
              <ChatMessage
                key={item.uid}
                nickname={item.nickname}
                avatarSrc={item.avatarSrc}
                message={item.message}
                time={item.time}
                selfMessage={item.selfMessage}
                repeatedMessageCount={item.repeatedMessageCount}
              />
            ))
          }
        </List>
      </Grid>
    );
  }
}

ChatBodyBar.propTypes = {
  classes: PropTypes.object.isRequired,
};

export default withStyles(styles)(ChatBodyBar);
