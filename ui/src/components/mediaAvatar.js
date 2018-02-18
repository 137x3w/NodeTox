import React from 'react';
import PropTypes from 'prop-types';
import { withStyles } from 'material-ui/styles';
import Avatar from 'material-ui/Avatar';

const styles = theme => ({
});

class MediaAvatar extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
    	src: props.src || "",
    	char: props.char || "",
    }
    this.classes = props.classes;
  }
  
  render() {
    return (    
			<Avatar alt="User avatar" src={ this.state.src }>
        { this.state.src ? null : this.state.char }
      </Avatar>
    );
  }
}

MediaAvatar.propTypes = {
  classes: PropTypes.object.isRequired,
};

export default withStyles(styles)(MediaAvatar);
