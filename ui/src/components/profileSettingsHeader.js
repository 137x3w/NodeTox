import React from 'react';
import PropTypes from 'prop-types';
import { withStyles } from 'material-ui/styles';
import Grid from 'material-ui/Grid';
import AppBar from 'material-ui/AppBar';
import Toolbar from 'material-ui/Toolbar';
import Typography from 'material-ui/Typography';
import MenuIcon from 'material-ui-icons/Menu';
import Avatar from 'material-ui/Avatar';
import IconButton from 'material-ui/IconButton';
import MoreVertIcon from 'material-ui-icons/MoreVert';
import Button from 'material-ui/Button';
import { CardHeader } from 'material-ui/Card';

const styles = theme => ({
  profileSettingsHeader: {

  },
  profileSettingsToolBar: {
    backgroundColor: theme.palette.primary.contrastText,
    minHeight: '80px',
  },
  profileSettingsBackButton: {
    marginRight: '24px',
  },
  profileSettingsTitle: {
    flex: 1,
  }
});

class ProfileSettingsHeader extends React.Component {
  constructor(props) {
    super(props);
    this.state = {};
    this.classes = props.classes;
  }

  handleProps(props) {
    var result = {
      backClickCallback: props.backClickCallback || (() => {}),
      saveClickCallback: props.saveClickCallback || (() => {}),
    };
    return result;
  }
  
  render() {
    this.safeProps = this.handleProps(this.props);
    return (    
      <Grid item className={ this.classes.profileSettingsHeader }>
        <AppBar position="static" elevation={2}>
          <Toolbar className={ this.classes.profileSettingsToolBar }>
            <IconButton className={ this.classes.profileSettingsBackButton } onClick={ this.safeProps.backClickCallback }>
              <MenuIcon/>
            </IconButton>
            <Typography noWrap variant="title" className={ this.classes.profileSettingsTitle }>
              Settings
            </Typography>
            <Button onClick={ this.safeProps.saveClickCallback }>
              Done
            </Button>
          </Toolbar>
        </AppBar>
      </Grid>
    );
  }
}

ProfileSettingsHeader.propTypes = {
  classes: PropTypes.object.isRequired,
};

export default withStyles(styles)(ProfileSettingsHeader);
