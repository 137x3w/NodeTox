import React from 'react';
import PropTypes from 'prop-types';
import { withStyles } from 'material-ui/styles';
import Grid from 'material-ui/Grid';
import ContactListItem from './contactListItem';

const styles = theme => ({
  profileBarContainer: {
    overflow: 'hidden',
    backgroundColor: theme.palette.primary.main,
  },
});

class ProfileBar extends React.Component {
  constructor(props) {
    super(props);
    this.classes = props.classes;
  }

  render() {
    return (
      <Grid item align="center" className={ this.classes.profileBarContainer }>
        <ContactListItem
          nickname={ this.props.nickname }
          statusMessage={ this.props.statusMessage }
          avatarSrc={ this.props.avatarSrc }
          connectionStatus={ this.props.connectionStatus }
          clickCallback={ this.props.clickCallback }
        />
      </Grid>
    );
  }
}

ProfileBar.propTypes = {
  classes: PropTypes.object.isRequired,
  avatarSrc: PropTypes.string,
  nickname: PropTypes.string,
  statusMessage: PropTypes.string,
  connectionStatus: PropTypes.string,
  clickCallback: PropTypes.func,
};

ProfileBar.defaultProps = {
  avatarSrc: "",
  nickname: "Default nickname",
  statusMessage: "Default status message",
  connectionStatus: "offline",
  clickCallback: (() => {}),
}

export default withStyles(styles)(ProfileBar);
