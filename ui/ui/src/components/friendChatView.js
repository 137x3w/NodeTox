import React from 'react';
import PropTypes from 'prop-types';
import FriendChatHeader from './friendChatHeaderBar';
import ChatBodyBar from './chatBodyBar';
import ChatTextInputBar from './chatTextInputBar';

class FriendChatView extends React.Component {
  render() {
    return (
    	<div>
        <FriendChatHeader
          avatarSrc={ this.props.chatHeader.avatarSrc } 
          nickname={ this.props.chatHeader.nickname }
          statusMessage={ this.props.chatHeader.statusMessage }
          connectionStatus={ this.props.chatHeader.connectionStatus }
          menuButtonClickCallback={ this.props.menuButtonClickCallback }
        />
	    	<ChatBodyBar
	        messages={ this.props.chatBody.messages }
	    	/>
        <ChatTextInputBar/>
    	</div>
    );
  }
}

FriendChatView.propTypes = {
  chatHeader: PropTypes.object,
  chatBody: PropTypes.object, 
  menuButtonClickCallback: PropTypes.func,
};

FriendChatView.defaultProps = {
  menuButtonClickCallback: (() => {}),
}

export default FriendChatView;
