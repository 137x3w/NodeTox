import React from 'react';
import PropTypes from 'prop-types';
import { withStyles } from 'material-ui/styles';
import ProfileSettingsHeader from './profileSettingsHeader';
import ProfileSettingsBody from './profileSettingsBody';

const styles = theme => ({});

class FriendChatView extends React.Component {
  constructor(props) {
    super(props);
    this.classes = props.classes;
    this.state = {};
  }

  handleProps(props) {
    var result = {
      header: props.header || {},
      body: props.body || [],
    }
    return result;
  }

  render() {
    this.safeProps = this.handleProps(this.props);
    return (
    	<div>
        <ProfileSettingsHeader
          backClickCallback={ this.safeProps.header.backClickCallback }
          saveClickCallback={ this.safeProps.body.saveClickCallback }
        />
        <ProfileSettingsBody
          nickname={ this.safeProps.body.nickname }
          statusMessage={ this.safeProps.body.statusMessage }
          toxid={ this.safeProps.body.toxid }
          profilePassword={ this.safeProps.body.profilePassword }
          avatarSrc={ this.safeProps.body.avatarSrc }
        />
    	</div>
    );
  }
}

FriendChatView.propTypes = {
  classes: PropTypes.object.isRequired,
};

export default withStyles(styles)(FriendChatView);
