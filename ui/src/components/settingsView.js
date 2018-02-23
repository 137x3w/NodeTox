import React from 'react';
import PropTypes from 'prop-types';
import { withStyles } from 'material-ui/styles';
import ProfileSettingsBody from './profileSettingsBody';

const styles = theme => ({});

class SettingsView extends React.Component {
  constructor(props) {
    super(props);
    this.classes = props.classes;
  }

  render() {
    return (
      <ProfileSettingsBody
        nickname={ this.props.body.nickname }
        statusMessage={ this.props.body.statusMessage }
        toxid={ this.props.body.toxid }
        profilePassword={ this.props.body.profilePassword }
        avatarSrc={ this.props.body.avatarSrc }
      />
    );
  }
}

SettingsView.propTypes = {
  classes: PropTypes.object.isRequired,
};

export default withStyles(styles)(SettingsView);
