import React from 'react';
import PropTypes from 'prop-types';
import { withStyles } from 'material-ui/styles';
import ProfileBar from './profileBar';
import ContactListBar from './contactListBar';

const styles = theme => ({
  fullHeight: {
    // height: '100%',
  },
});

class SideView extends React.Component {
	constructor(props) {
    super(props);
    this.classes = props.classes;
  }
  render() {
    return (
    	<div className={ this.classes.fullHeight }>
	    	<ProfileBar
	    		profileBar={ this.props.profileBar } 
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

export default withStyles(styles)(SideView);
