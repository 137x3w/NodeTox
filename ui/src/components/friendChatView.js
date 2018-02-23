import React from 'react';
import PropTypes from 'prop-types';
import { withStyles } from 'material-ui/styles';
import FriendChatHeader from './friendChatHeaderBar';
import ChatBodyBar from './chatBodyBar';
import ChatTextInputBar from './chatTextInputBar';

const styles = theme => ({});

class FriendChatView extends React.Component {
  constructor(props) {
    super(props);
    this.classes = props.classes;
    this.state = {};
  }

  handleProps(props) {
    var result = {
      chatHeader: props.chatHeader || {},
      chatBody: props.chatBody || [],
    }
    return result;
  }

  render() {
    this.safeProps = this.handleProps(this.props);
    return (
    	<div>
        <FriendChatHeader
          avatarSrc={ this.safeProps.chatHeader.avatarSrc } 
          nickname={ this.safeProps.chatHeader.nickname }
          statusMessage={ this.safeProps.chatHeader.statusMessage }
          connectionStatus={ this.safeProps.chatHeader.connectionStatus }
          menuButtonClickCallback={ this.safeProps.chatHeader.menuButtonClickCallback }
        />
	    	<ChatBodyBar
	        messages={ this.safeProps.chatBody.messages }
	    	/>
        <ChatTextInputBar/>
    	</div>
    );
  }
}

FriendChatView.propTypes = {
  classes: PropTypes.object.isRequired,
};

export default withStyles(styles)(FriendChatView);
