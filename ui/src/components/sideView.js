import React from 'react';
import PropTypes from 'prop-types';
import { withStyles } from 'material-ui/styles';
import ProfileBar from './profileBar';
import ContactListBar from './contactListBar';

const styles = theme => ({});

class SideView extends React.Component {
  constructor(props) {
    super(props);
    this.classes = props.classes;
    this.state = {};
  }

  handleProps(props) {
    var result = {
    	profileBar: props.profileBar || {},
    	contactList: props.contactList || {},
    }
    return result;
  }

  render() {
    this.safeProps = this.handleProps(this.props);
    return (
    	<div>
	    	<ProfileBar 
	        nickname={ this.safeProps.profileBar.nickname }
		      statusMessage={ this.safeProps.profileBar.statusMessage }
		      avatarSrc={ this.safeProps.profileBar.avatarSrc }
		      connectionStatus={ this.safeProps.profileBar.connectionStatus }
		      avatarClickCallback={ this.safeProps.profileBar.avatarClickCallback }
	    	/>
	    	<ContactListBar
	        contacts={ this.safeProps.contactList.contacts }
	      	contactListItemClickCallback={ this.safeProps.contactList.contactListItemClickCallback }
	    	/>
    	</div>
    );
  }
}

SideView.propTypes = {
  classes: PropTypes.object.isRequired,
};

export default withStyles(styles)(SideView);
