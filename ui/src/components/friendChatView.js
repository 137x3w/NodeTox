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
          friendUid={ this.props.friendChatView.header.friendUid }
          avatarSrc={ this.props.friendChatView.header.avatarSrc } 
          nickname={ this.props.friendChatView.header.nickname }
          statusMessage={ this.props.friendChatView.header.statusMessage }
          connectionStatus={ this.props.friendChatView.header.connectionStatus }
          userStatus={ this.props.friendChatView.header.userStatus }
          menuButtonClickCallback={ this.props.menuButtonClickCallback }
        />
	    	<ChatBodyBar
	        messages={ this.props.friendChatView.body.messages }
	    	/>
        <ChatTextInputBar
          sendMessageCallback={ this.props.friendChatView.footer.sendMessageCallback }
        />
    	</div>
    );
  }
}

FriendChatView.propTypes = {
  friendChatView: PropTypes.object,
  menuButtonClickCallback: PropTypes.func,
};

FriendChatView.defaultProps = {
  menuButtonClickCallback: (() => {}),
}

export default FriendChatView;
