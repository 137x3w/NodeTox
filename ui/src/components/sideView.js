import React from 'react';
import PropTypes from 'prop-types';
import ProfileBar from './profileBar';
import ContactListBar from './contactListBar';

class SideView extends React.Component {
  render() {
    return (
    	<div>
	    	<ProfileBar 
	        nickname={ this.props.profileBar.nickname }
		      statusMessage={ this.props.profileBar.statusMessage }
		      avatarSrc={ this.props.profileBar.avatarSrc }
		      connectionStatus={ this.props.profileBar.connectionStatus }
		      clickCallback={ this.props.profileBarClickCallback }
	    	/>
	    	<ContactListBar
	        contacts={ this.props.contactList.contacts }
	      	contactClickCallback={ this.props.contactListItemClickCallback }
	    	/>
    	</div>
    );
  }
}

SideView.propTypes = {
  contactListItemClickCallback: PropTypes.func,
  profileBarClickCallback: PropTypes.func,
};

SideView.defaultProps = {
	contactListItemClickCallback: (() => {}),
	profileBarClickCallback: (() => {}),
}

export default SideView;
